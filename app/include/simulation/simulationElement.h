#pragma once
#include "position.h"
#include <QGraphicsEllipseItem>
#include <QBrush>

/*
Diese Klasse ist ein Basisklasse für alle Simulationselemente.
*/


class simulationElement: public Position {
private:
    bool solidStatus;
    double radius;

public:
    double getX() const;
    double getY() const;
    QPointF getPosition() const;

    simulationElement(double x, double y,Qt::GlobalColor color,bool solidStatus, double radius = 20.0);
    bool istSolid() const;
    void setSolid(bool solid);
    double holeRadius() const;
    virtual ~simulationElement() = default;

};
