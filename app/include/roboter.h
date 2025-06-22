#pragma once
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include "BewegungsRoboter.h"
#include "Dc-SignalInterpreter.h"
#include "GpsSensor.h"
class Roboter : public QGraphicsEllipseItem {
private:
    BewegungsRoboter bewegung;

    GPSSensor* gpsSensor;
public:
    Roboter(double x = 0.0, double y = 0.0, double radius = 20.0);
    ~Roboter() = default;
    void empfangesignal(signaltyp);
    void updateLogic(float dt);
    void syncGraphics();

    Roboter(double x, double y, double radius, GPSSensor* gps = nullptr);
protected:
    void keyPressEvent(QKeyEvent *event) override;
};


