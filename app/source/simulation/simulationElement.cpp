#include "simulationElement.h"
#include <QBrush>
#include <QPen>

void simulationElement::setSolid(bool solid) {
    this->solidStatus = solid;
}
bool simulationElement::istSolid() const {
    return this->solidStatus;
}
simulationElement::simulationElement(double x, double y, Qt::GlobalColor color,bool solidStatus,double radius)
    : Position(x, y, radius) {
    setSolid(solidStatus);
    setBrush(QBrush(Qt::transparent));
    setPen(QPen(Qt::transparent));
    this->radius = radius;
}
double simulationElement::holeRadius() const {
    return this->radius;
}

double simulationElement::getX() const {
    return holePosition().x();  // Oder wie immer du X in Position bekommst
}

double simulationElement::getY() const {
    return holePosition().y();
}

QPointF simulationElement::getPosition() const {
    return QPointF(getX(), getY());
}

