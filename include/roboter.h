#pragma once
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include "BewegungsRoboter.h"
#include "Dc-SignalInterpreter.h"

class Roboter : public QGraphicsEllipseItem {
private:
    BewegungsRoboter bewegung;

public:
    Roboter(double x = 0.0, double y = 0.0, double radius = 20.0);
    ~Roboter() = default;

    /* passerelles */
    void empfangeSignal(signaltyp);
    void updateLogic(float dt);
    void syncGraphics();

protected:
    void keyPressEvent(QKeyEvent *event) override;   // ← on garde
};
