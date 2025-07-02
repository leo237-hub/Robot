#include "gasSimulationElement.h"
#include <QtMath>
#include <QBrush>
#include <QPen>

GasSimulationElement::GasSimulationElement(double x, double y, Qt::GlobalColor color, bool solidStatus, double radius, float gasKonzentration)
    : simulationElement(x, y, color, solidStatus, radius), gasKonzentration(gasKonzentration) {
    
    setRect(0, 0, 1.5*radius, 1.5*radius);
    setBrush(Qt::transparent); // Rendere invisibile
    setPen(QPen(Qt::transparent)); // Bordo trasparente
    setPos(x, y);
    this->gasKonzentration = gasKonzentration;
}

float GasSimulationElement::holeGasKonzentration() {
    return this->gasKonzentration;
} 