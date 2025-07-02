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
#include "TemperaturSensor.h"
#include "Lidarsensor.h"
#include "Gassensor.h"
#include "Wassersensor.h"
#include "Kettesensor.h"
#include "selfcheck.h"
#include "LEDPanel.h"
#include "Drehmotor.h"
#include "DreheSignalInterpreter.h"
#define PI 3.14159265f
using namespace std;



GraphischesRoboter::GraphischesRoboter(double x, double y, double radius, GPSSensor* gps)
    : QObject(), QGraphicsEllipseItem(), bewegung(x, y, 0.0f), gpsSensor(gps), aktuellesSignal(signaltyp::keine), istInBewegung(false), selfcheck(nullptr), selfcheckTimer(nullptr), ledPanel(nullptr) {
    
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

    // Inizializza sensori ridondanti
    for (int i = 0; i < 3; ++i) {
        tempSensor[i] = new TemperaturSensor();
        lidarSensor[i] = new LidarSensor(10.0, 10); // parametri dummy, KEIN nullptr mehr
        gpsSensorArr[i] = new GPSSensor();
        gasSensor[i] = new GasSensor();
        wasserSensor[i] = new Wassersensor();
        ketteSensor[i] = new Kettensensor();
    }
    gpsSensor = gpsSensorArr[0];
    selfcheck = new Selfcheck(tempSensor, lidarSensor, gpsSensorArr, gasSensor, wasserSensor, ketteSensor);
    // Timer per selfcheck periodico
    selfcheckTimer = new QTimer(this);
    connect(selfcheckTimer, &QTimer::timeout, this, [this]() {
        if (!ledPanel || !selfcheck) return;
        if (!sensorenAktiv) {
            ledPanel->setzeTemperaturSensorStatus(false);
            ledPanel->setzeGassensorStatus(false);
            ledPanel->setzeWassersensorStatus(false);
            ledPanel->setzeGPSStatus(false);
            return;
        }
        auto tempRes = selfcheck->TemperaturSensPruefen();
        ledPanel->setzeTemperaturSensorStatus(tempRes == "OK");
        auto gasRes = selfcheck->GassensorPruefen();
        ledPanel->setzeGassensorStatus(gasRes == "OK");
        auto wasserRes = selfcheck->WasserSensPruefen();
        ledPanel->setzeWassersensorStatus(wasserRes == "OK");
        auto gpsRes = selfcheck->GPsSensorPruefen();
        ledPanel->setzeGPSStatus(gpsRes == "OK");
    });
    selfcheckTimer->start(500); // ogni 500ms
}

GraphischesRoboter::GraphischesRoboter(TemperaturSensor* t[3], LidarSensor* l[3], GPSSensor* g[3], GasSensor* gas[3], Wassersensor* w[3], Kettensensor* k[3], double x, double y, double radius)
    : QObject(), QGraphicsEllipseItem(), bewegung(x, y, 0.0f), gpsSensor(nullptr), aktuellesSignal(signaltyp::keine), istInBewegung(false), selfcheck(nullptr), selfcheckTimer(nullptr), ledPanel(nullptr) {
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
    bewegungsSimulation = new BewegungsSimulation(&bewegung);
    bewegungsSimulation->setzePosition(x, y, 0.0f);
    bewegungsTimer = new QTimer(this);
    connect(bewegungsTimer, &QTimer::timeout, this, &GraphischesRoboter::bewegungAktualisieren);
    bewegungsTimer->start(50);
    // Usa le istanze condivise
    for (int i = 0; i < 3; ++i) {
        tempSensor[i] = t[i];
        lidarSensor[i] = l[i];
        gpsSensorArr[i] = g[i];
        gasSensor[i] = gas[i];
        wasserSensor[i] = w[i];
        ketteSensor[i] = k[i];
    }
    gpsSensor = gpsSensorArr[0];
    selfcheck = new Selfcheck(tempSensor, lidarSensor, gpsSensorArr, gasSensor, wasserSensor, ketteSensor);
    selfcheckTimer = new QTimer(this);
    connect(selfcheckTimer, &QTimer::timeout, this, [this]() {
        if (!ledPanel || !selfcheck) return;
        if (!sensorenAktiv) {
            ledPanel->setzeTemperaturSensorStatus(false);
            ledPanel->setzeGassensorStatus(false);
            ledPanel->setzeWassersensorStatus(false);
            ledPanel->setzeGPSStatus(false);
            return;
        }
        auto tempRes = selfcheck->TemperaturSensPruefen();
        ledPanel->setzeTemperaturSensorStatus(tempRes == "OK");
        auto gasRes = selfcheck->GassensorPruefen();
        ledPanel->setzeGassensorStatus(gasRes == "OK");
        auto wasserRes = selfcheck->WasserSensPruefen();
        ledPanel->setzeWassersensorStatus(wasserRes == "OK");
        auto gpsRes = selfcheck->GPsSensorPruefen();
        ledPanel->setzeGPSStatus(gpsRes == "OK");
    });
    selfcheckTimer->start(500);
    drehmotor = new Drehmotor();
    drehInterpreter = new DreheSignalInterpreter();
    drehInterpreter->setzeDrehmotor(drehmotor);
}

GraphischesRoboter::~GraphischesRoboter() {
    if (bewegungsTimer) {
        bewegungsTimer->stop();
        delete bewegungsTimer;
    }
    if (bewegungsSimulation) {
        delete bewegungsSimulation;
    }
    if (selfcheckTimer) {
        selfcheckTimer->stop();
        delete selfcheckTimer;
    }
    if (selfcheck) delete selfcheck;
    for (int i = 0; i < 3; ++i) {
        delete tempSensor[i];
        delete lidarSensor[i];
        delete gpsSensorArr[i];
        delete gasSensor[i];
        delete wasserSensor[i];
        delete ketteSensor[i];
    }
}

void GraphischesRoboter::empfangeJoystick1(signaltyp s) {
    bewegung.EmpfangeJoystick1(s);
}

void GraphischesRoboter::empfangeJoystick2(signaltyp s) {
    qDebug() << "empfangeJoystick2 chiamato con segnale:" << static_cast<int>(s);
    if (!drehInterpreter) return;
    if (s == signaltyp::DrehenLinks) {
        drehInterpreter->drehenLinks();
    } else if (s == signaltyp::DrehenRechts) {
        drehInterpreter->drehenRechts();
    } else {
        // Niente o stop
        drehInterpreter->verarbeiteRotation(0.0f, 0.0f);
    }
}

void GraphischesRoboter::logikAktualisieren(float dt){
    bewegungsSimulation->aktualisierePosition(dt);
}

void GraphischesRoboter::grafikSynchronisieren() {
    float x = bewegungsSimulation->getX();
    float y = bewegungsSimulation->getY();

    setPos(x, y);
    setRotation(bewegungsSimulation->getWinkel());

    for (int i = 0; i < 3; ++i) {
        if (gpsSensorArr[i]) {
            gpsSensorArr[i]->setPosition(x, y);
        }
    }

    if (scene()) scene()->update();
}

void GraphischesRoboter::bewegungAktualisieren() {
    logikAktualisieren(0.05f);
    grafikSynchronisieren();
}

void GraphischesRoboter::setzeBlockVorwaerts(bool blockiert) {
    bewegung.setzeBlockVorwaerts(blockiert);
}

void GraphischesRoboter::keyPressEvent(QKeyEvent *event){
    qDebug() << "keyPressEvent: key=" << event->key() << "text=" << event->text() << "modifiers=" << event->modifiers();
    if (istInBewegung) return; /* Ignoriere wenn bereits in Bewegung */
    Dc_SignalInterpreter Interpreter;
    std::string eingabe;
    signaltyp Signal = signaltyp::keine;

    switch(event->key()){
    case Qt::Key_W:
        eingabe = "w";
        Signal = Interpreter.EingabeInterpretieren(eingabe);
        empfangeJoystick1(Signal);
        break;
    case Qt::Key_A:
        eingabe = "a";
        Signal = Interpreter.EingabeInterpretieren(eingabe);
        empfangeJoystick1(Signal);
        break;
    case Qt::Key_S:
        eingabe = "s";
        Signal = Interpreter.EingabeInterpretieren(eingabe);
        empfangeJoystick1(Signal);
        break;
    case Qt::Key_D:
        eingabe = "d";
        Signal = Interpreter.EingabeInterpretieren(eingabe);
        empfangeJoystick1(Signal);
        break;
    case Qt::Key_J:
        empfangeJoystick2(signaltyp::DrehenLinks);
        break;
    case Qt::Key_L:
        empfangeJoystick2(signaltyp::DrehenRechts);
        break;
    default:
        return;
    }

    if (Signal != signaltyp::keine) {
        aktuellesSignal = Signal;
        istInBewegung = true;
        logikAktualisieren(0.05f);
        grafikSynchronisieren();
        event->accept();
        return;
    }
    event->accept();
}

void GraphischesRoboter::keyReleaseEvent(QKeyEvent *event) {
    switch(event->key()){
    case Qt::Key_W:
    case Qt::Key_A:
    case Qt::Key_S:
    case Qt::Key_D:
        /* Stoppe Bewegung */
        istInBewegung = false;
        aktuellesSignal = signaltyp::keine;
        empfangeJoystick1(signaltyp::keine);
        logikAktualisieren(0.05f);
        grafikSynchronisieren();
        break;
    case Qt::Key_J:
        empfangeJoystick2(signaltyp::keine);
        break;
    case Qt::Key_L:
        empfangeJoystick2(signaltyp::keine);
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
    sensorenAktiv = aktiv;
    for (int i = 0; i < 3; ++i) {
        if (sensorenAktiv) {
            tempSensor[i]->starten();
            gasSensor[i]->starten();
            wasserSensor[i]->starten();
        } else {
            tempSensor[i]->stoppen();
            gasSensor[i]->stoppen();
            wasserSensor[i]->stoppen();
        }
    }
    if (!ledPanel) return;
    if (!sensorenAktiv) {
        ledPanel->setzeTemperaturSensorStatus(false);
        ledPanel->setzeGassensorStatus(false);
        ledPanel->setzeWassersensorStatus(false);
        ledPanel->setzeGPSStatus(false);
    }
}

void GraphischesRoboter::focusOutEvent(QFocusEvent *event) {
    istInBewegung = false;
    aktuellesSignal = signaltyp::keine;
    empfangeJoystick1(signaltyp::keine);
    logikAktualisieren(0.05f);
    grafikSynchronisieren();
    QGraphicsEllipseItem::focusOutEvent(event);
}

void GraphischesRoboter::setLEDPanel(LEDPanel* panel) {
    ledPanel = panel;
}

void GraphischesRoboter::dreheKopfLinks() {
    if (drehInterpreter) drehInterpreter->verarbeiteRotation(270.0f, 100.0f); // 270° = links
}

void GraphischesRoboter::dreheKopfRechts() {
    if (drehInterpreter) drehInterpreter->verarbeiteRotation(90.0f, 100.0f); // 90° = rechts
}

