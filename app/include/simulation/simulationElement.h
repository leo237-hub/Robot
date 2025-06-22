#pragma once
#include "Position.h"
#include <QgraphicsEllipseItem>
#include <QBrush>

/*
Diese Klasse ist ein Basisklasse für alle Simulationselemente.
*/


class simulationElement: public Position {
private:
    bool solidStatus;
    double radius;

public:

    simulationElement(double x, double y,Qt::GlobalColor color,bool solidStatus, double radius = 20.0);
    bool istSolid() const;
    void setSolid(bool solid);
    double holeRadius() const;
    virtual ~simulationElement() = default;

};
