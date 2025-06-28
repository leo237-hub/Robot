#pragma once
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include <QTimer>
#include <QObject>
#include "BewegungsRoboter.h"
#include "BewegungsSimulation.h"
#include "Dc-SignalInterpreter.h"
#include "GpsSensor.h"

class GraphischesRoboter : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT

private:
    BewegungsRoboter bewegung;
    BewegungsSimulation* bewegungsSimulation;
    GPSSensor* gpsSensor;
    QTimer* movementTimer;
    signaltyp currentSignal;
    bool moving;

public:
    GraphischesRoboter(double x = 0.0, double y = 0.0, double radius = 20.0);
    ~GraphischesRoboter();
    void empfangesignal(signaltyp);
    void updateLogic(float dt);
    void syncGraphics();
    bool isMoving() const { return moving; }

    GraphischesRoboter(double x, double y, double radius, GPSSensor* gps = nullptr);
    
    // Öffentliche Methoden für Tastatur-Events
    void handleKeyPress(QKeyEvent *event);
    void handleKeyRelease(QKeyEvent *event);
    
    // Methode für Roboter-Status
    void setzeRoboterAktiv(bool aktiv);
    
private slots:
    void updateMovement();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
}; 