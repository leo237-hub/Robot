/*
Zweck und Verhalten der GraphischesRoboter-Klasse

Zweck:
Stellt einen grafischen Roboter dar, der sowohl die grafische Repräsentation als auch die Logik für Bewegung, Signalverarbeitung und Interaktion mit Sensoren übernimmt.

Verhalten:
Synchronisiert die grafische Darstellung mit dem internen Zustand, verarbeitet Tastatureingaben und steuert die Bewegung und Statusanzeige des Roboters in der Simulation.
*/
#pragma once
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include <QTimer>
#include <QObject>
#include "BewegungsRoboter.h"
#include "BewegungsSimulation.h"
#include "Dc-SignalInterpreter.h"
#include "GpsSensor.h"
#include "TemperaturSensor.h"
#include "Lidarsensor.h"
#include "GasSensor.h"
#include "Wassersensor.h"
#include "Kettesensor.h"
#include "selfcheck.h"
#include "LEDPanel.h"
#include "DreheSignalinterpreter.h"
#include "drehmotor.h"

class GraphischesRoboter : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT

private:
    BewegungsRoboter bewegung;
    BewegungsSimulation* bewegungsSimulation;
    GPSSensor* gpsSensor;
    QTimer* bewegungsTimer;
    signaltyp aktuellesSignal;
    bool istInBewegung;
    bool blockVorwaerts = false;
    bool sensorenAktiv = false;

    TemperaturSensor* tempSensor[3];
    LidarSensor* lidarSensor[3];
    GPSSensor* gpsSensorArr[3];
    GasSensor* gasSensor[3];
    Wassersensor* wasserSensor[3];
    Kettensensor* ketteSensor[3];

    Selfcheck* selfcheck;
    QTimer* selfcheckTimer;
    LEDPanel* ledPanel;

    DreheSignalInterpreter* drehInterpreter = nullptr;
    Drehmotor* drehmotor = nullptr;

public:
    GraphischesRoboter(TemperaturSensor* t[3], LidarSensor* l[3], GPSSensor* g[3], GasSensor* gas[3], Wassersensor* w[3], Kettensensor* k[3], double x = 0.0, double y = 0.0, double radius = 20.0);
    ~GraphischesRoboter();
    void empfangeJoystick1(signaltyp s);
    void empfangeJoystick2(signaltyp s);
    void logikAktualisieren(float dt);
    void grafikSynchronisieren();
    bool bewegtSich() const { return istInBewegung; }

    GraphischesRoboter(double x, double y, double radius, GPSSensor* gps = nullptr);
    
    void tastaturDruckBehandeln(QKeyEvent *event);
    void tastaturLoslassenBehandeln(QKeyEvent *event);
    
    void setzeRoboterAktiv(bool aktiv);
    
    void setzeBlockVorwaerts(bool blockiert);
    
    void setLEDPanel(LEDPanel* panel);
    
    void dreheKopfLinks();
    void dreheKopfRechts();
    
private slots:
    void bewegungAktualisieren();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void focusOutEvent(QFocusEvent *event) override;
}; 