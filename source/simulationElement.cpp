#include "simulationElement.h"
#include <QBrush>

void simulationElement::setSolid(bool solid) {
    this->solidStatus = solid;
}
bool simulationElement::istSolid() const {
    return this->solidStatus;
}
simulationElement::simulationElement(double x, double y, Qt::GlobalColor color,bool solidStatus,double radius)
    : Position(x, y, radius) {
    setSolid(solidStatus);
    setBrush(QBrush(color));
}
double simulationElement::holeRadius() const {
    return this->radius;
}

