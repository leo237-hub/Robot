#include <QBrush>
#include <iostream>
#include <cmath>
#include <QString>
#include <QDebug>
#include <string>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "roboter.h"
#include "dcmotor.h"
#include "Dc-SignalInterpreter.h"
#include "BewegungsRoboter.h"
#define PI 3.14159265f
using namespace std;
Roboter::Roboter(double x, double y, double radius, GPSSensor* gps)
    :bewegung(x, y, 30.0f), gpsSensor(gps){
    
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
}
void Roboter::empfangesignal(signaltyp s){
    bewegung.Empfangesignal(s);
}

void Roboter::updateLogic(float dt){
    bewegung.Aktualisiereposition(dt);
}

void Roboter::syncGraphics() {
    float x = bewegung.getx();
    float y = bewegung.gety();

    setPos(x, y);
    setRotation(bewegung.getrichtung());

    if (gpsSensor) {
        gpsSensor->setPosition(x, y);
    }

    if (scene()) scene()->update();
}

void Roboter::keyPressEvent(QKeyEvent *event){
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
        qDebug() << "Bewegung Beendet.";
        return;
    default:
        qDebug() << "Unbekannte Taste.";
        return;
    }
    empfangesignal(Signal);
    updateLogic(0.5f);
    syncGraphics();
    event ->accept();
}
