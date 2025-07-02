#include <QBrush>
#include <iostream>
#include <cmath>
#include <QString>
#include <string>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QFocusEvent>
#include "GraphischesRoboter.h"
#include "dcmotor.h"
#include "Dc-SignalInterpreter.h"
#include "BewegungsRoboter.h"
#include "BewegungsSimulation.h"
#include "GpsSensor.h"
#define PI 3.14159265f
using namespace std;

GraphischesRoboter::GraphischesRoboter(double x, double y, double radius)
    : QObject(), QGraphicsEllipseItem(), bewegung(x, y, 0.0f), gpsSensor(nullptr), aktuellesSignal(signaltyp::keine), istInBewegung(false){
    
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
    
    /* Erstelle BewegungsSimulation */
    bewegungsSimulation = new BewegungsSimulation(&bewegung);
    bewegungsSimulation->setzePosition(x, y, 0.0f);
    
    /* Timer für kontinuierliche Bewegung - langsamer für kontrolliertere Bewegung */
    bewegungsTimer = new QTimer(this);
    connect(bewegungsTimer, &QTimer::timeout, this, &GraphischesRoboter::bewegungAktualisieren);
    bewegungsTimer->start(50); /* 50ms = 20 FPS für kontrolliertere Bewegung */
}

GraphischesRoboter::GraphischesRoboter(double x, double y, double radius, GPSSensor* gps)
    : QObject(), QGraphicsEllipseItem(), bewegung(x, y, 0.0f), gpsSensor(gps), aktuellesSignal(signaltyp::keine), istInBewegung(false){
    
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
    
    /* Erstelle BewegungsSimulation */
    bewegungsSimulation = new BewegungsSimulation(&bewegung);
    bewegungsSimulation->setzePosition(x, y, 0.0f);
    
    /* Timer für kontinuierliche Bewegung - langsamer für kontrolliertere Bewegung */
    bewegungsTimer = new QTimer(this);
    connect(bewegungsTimer, &QTimer::timeout, this, &GraphischesRoboter::bewegungAktualisieren);
    bewegungsTimer->start(50); /* 50ms = 20 FPS für kontrolliertere Bewegung */
}

GraphischesRoboter::~GraphischesRoboter() {
    if (bewegungsTimer) {
        bewegungsTimer->stop();
        delete bewegungsTimer;
    }
    if (bewegungsSimulation) {
        delete bewegungsSimulation;
    }
}

void GraphischesRoboter::empfangesignal(signaltyp s){
    bewegung.Empfangesignal(s);
}

void GraphischesRoboter::logikAktualisieren(float dt){
    bewegungsSimulation->aktualisierePosition(dt);
}

void GraphischesRoboter::grafikSynchronisieren() {
    float x = bewegungsSimulation->getX();
    float y = bewegungsSimulation->getY();

    setPos(x, y);
    setRotation(bewegungsSimulation->getWinkel());

    if (gpsSensor) {
        gpsSensor->setPosition(x, y);
    }

    if (scene()) scene()->update();
}

void GraphischesRoboter::bewegungAktualisieren() {
    if (istInBewegung) {
        /* Kontinuierliche Bewegung während Taste gedrückt ist */
        empfangesignal(aktuellesSignal);
        logikAktualisieren(0.05f); /* 50ms = 20 FPS für kontrolliertere Bewegung */
        grafikSynchronisieren();
    } else {
        empfangesignal(signaltyp::keine);
        logikAktualisieren(0.05f);
        grafikSynchronisieren();
    }
}

void GraphischesRoboter::setzeBlockVorwaerts(bool blockiert) {
    bewegung.setzeBlockVorwaerts(blockiert);
}

void GraphischesRoboter::keyPressEvent(QKeyEvent *event){
    if (istInBewegung) return; /* Ignoriere wenn bereits in Bewegung */
    
    signaltyp Signal;
    Dc_SignalInterpreter Interpreter;
    
    switch(event->key()){
    case Qt::Key_W:
    case Qt::Key_Up:
        if (blockVorwaerts) return; // Blockiere vorwärts
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
    
    /* Starte kontinuierliche Bewegung */
    aktuellesSignal = Signal;
    istInBewegung = true;
    
    /* Erste Bewegung sofort ausführen */
    empfangesignal(Signal);
    logikAktualisieren(0.05f);
    grafikSynchronisieren();
    
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
        /* Stoppe Bewegung */
        istInBewegung = false;
        aktuellesSignal = signaltyp::keine;
        empfangesignal(signaltyp::keine);
        logikAktualisieren(0.05f);
        grafikSynchronisieren();
        break;
    default:
        break;
    }
    
    event->accept();
}

void GraphischesRoboter::tastaturDruckBehandeln(QKeyEvent *event) {
    keyPressEvent(event);
}

void GraphischesRoboter::tastaturLoslassenBehandeln(QKeyEvent *event) {
    keyReleaseEvent(event);
}

void GraphischesRoboter::setzeRoboterAktiv(bool aktiv) {
    bewegung.setzeAktiv(aktiv);
}

void GraphischesRoboter::focusOutEvent(QFocusEvent *event) {
    istInBewegung = false;
    aktuellesSignal = signaltyp::keine;
    empfangesignal(signaltyp::keine);
    logikAktualisieren(0.05f);
    grafikSynchronisieren();
    QGraphicsEllipseItem::focusOutEvent(event);
}

