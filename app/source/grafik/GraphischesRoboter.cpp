#include <QBrush>
#include <iostream>
#include <cmath>
#include <QString>
#include <string>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include "GraphischesRoboter.h"
#include "dcmotor.h"
#include "Dc-SignalInterpreter.h"
#include "BewegungsRoboter.h"
#include "BewegungsSimulation.h"
#include "GpsSensor.h"
#define PI 3.14159265f
using namespace std;

GraphischesRoboter::GraphischesRoboter(double x, double y, double radius)
    : QObject(), QGraphicsEllipseItem(), bewegung(x, y, 0.0f), gpsSensor(nullptr), currentSignal(signaltyp::keine), moving(false){
    
    setRect(0, 0, radius, radius);
    
    QRadialGradient gradient(radius * 0.8, radius/2, radius * 0.3); 
    gradient.setColorAt(0, Qt::red);       
    gradient.setColorAt(0.5, Qt::blue);    
    gradient.setColorAt(1, Qt::blue);       
    
    setBrush(gradient);
    
    setTransformOriginPoint(rect().center());
    setPos(x, y);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    
    // Erstelle BewegungsSimulation
    bewegungsSimulation = new BewegungsSimulation(&bewegung);
    bewegungsSimulation->setzePosition(x, y, 0.0f);
    
    // Timer für kontinuierliche Bewegung - langsamer für kontrolliertere Bewegung
    movementTimer = new QTimer(this);
    connect(movementTimer, &QTimer::timeout, this, &GraphischesRoboter::updateMovement);
    movementTimer->start(50); // 50ms = 20 FPS für kontrolliertere Bewegung
}

GraphischesRoboter::GraphischesRoboter(double x, double y, double radius, GPSSensor* gps)
    : QObject(), QGraphicsEllipseItem(), bewegung(x, y, 0.0f), gpsSensor(gps), currentSignal(signaltyp::keine), moving(false){
    
    setRect(0, 0, radius, radius);
    
    QRadialGradient gradient(radius * 0.8, radius/2, radius * 0.3); 
    gradient.setColorAt(0, Qt::red);       
    gradient.setColorAt(0.5, Qt::blue);    
    gradient.setColorAt(1, Qt::blue);       
    
    setBrush(gradient);
    
    setTransformOriginPoint(rect().center());
    setPos(x, y);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    
    // Erstelle BewegungsSimulation
    bewegungsSimulation = new BewegungsSimulation(&bewegung);
    bewegungsSimulation->setzePosition(x, y, 0.0f);
    
    // Timer für kontinuierliche Bewegung - langsamer für kontrolliertere Bewegung
    movementTimer = new QTimer(this);
    connect(movementTimer, &QTimer::timeout, this, &GraphischesRoboter::updateMovement);
    movementTimer->start(50); // 50ms = 20 FPS für kontrolliertere Bewegung
}

GraphischesRoboter::~GraphischesRoboter() {
    if (movementTimer) {
        movementTimer->stop();
        delete movementTimer;
    }
    if (bewegungsSimulation) {
        delete bewegungsSimulation;
    }
}

void GraphischesRoboter::empfangesignal(signaltyp s){
    bewegung.Empfangesignal(s);
}

void GraphischesRoboter::updateLogic(float dt){
    bewegungsSimulation->aktualisierePosition(dt);
}

void GraphischesRoboter::syncGraphics() {
    float x = bewegungsSimulation->getX();
    float y = bewegungsSimulation->getY();

    setPos(x, y);
    setRotation(bewegungsSimulation->getWinkel());

    if (gpsSensor) {
        gpsSensor->setPosition(x, y);
    }

    if (scene()) scene()->update();
}

void GraphischesRoboter::updateMovement() {
    if (moving) {
        // Kontinuierliche Bewegung während Taste gedrückt ist
        empfangesignal(currentSignal);
        updateLogic(0.05f); // 50ms = 20 FPS für kontrolliertere Bewegung
        syncGraphics();
    }
}

void GraphischesRoboter::keyPressEvent(QKeyEvent *event){
    if (moving) return; // Ignoriere wenn bereits in Bewegung
    
    signaltyp Signal;
    Dc_SignalInterpreter Interpreter;
    
    switch(event->key()){
    case Qt::Key_W:
    case Qt::Key_Up:
        Signal = Interpreter.EingabeInterpretieren("w");
        break;
    case Qt::Key_A:
    case Qt::Key_Left:
        Signal = Interpreter.EingabeInterpretieren("a");
        break;
    case Qt::Key_S:
    case Qt::Key_Down:
        Signal = Interpreter.EingabeInterpretieren("s");
        break;
    case Qt::Key_D:
    case Qt::Key_Right:
        Signal = Interpreter.EingabeInterpretieren("d");
        break;
    case Qt::Key_Q:
        return;
    default:
        return;
    }
    
    // Starte kontinuierliche Bewegung
    currentSignal = Signal;
    moving = true;
    
    // Erste Bewegung sofort ausführen
    empfangesignal(Signal);
    updateLogic(0.05f);
    syncGraphics();
    
    event->accept();
}

void GraphischesRoboter::keyReleaseEvent(QKeyEvent *event) {
    switch(event->key()){
    case Qt::Key_W:
    case Qt::Key_Up:
    case Qt::Key_A:
    case Qt::Key_Left:
    case Qt::Key_S:
    case Qt::Key_Down:
    case Qt::Key_D:
    case Qt::Key_Right:
        // Stoppe Bewegung
        moving = false;
        currentSignal = signaltyp::keine;
        empfangesignal(signaltyp::keine);
        updateLogic(0.05f);
        syncGraphics();
        break;
    default:
        break;
    }
    
    event->accept();
}

void GraphischesRoboter::handleKeyPress(QKeyEvent *event) {
    keyPressEvent(event);
}

void GraphischesRoboter::handleKeyRelease(QKeyEvent *event) {
    keyReleaseEvent(event);
}

void GraphischesRoboter::setzeRoboterAktiv(bool aktiv) {
    bewegung.setzeAktiv(aktiv);
} 