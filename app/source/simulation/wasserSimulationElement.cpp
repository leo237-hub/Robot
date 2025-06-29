#include "wasserSimulationElement.h"
#include <QtMath>
#include <QBrush>
#include <QPen>

WasserSimulationElement::WasserSimulationElement(double x, double y, Qt::GlobalColor color, bool solidStatus, double radius, float wasserKonzentration)
    : simulationElement(x, y, color, solidStatus, radius), wasserKonzentration(wasserKonzentration) {
    
    setRect(0, 0, 1.5*radius, 1.5*radius);
    setBrush(Qt::transparent); // Rendere invisibile
    setPen(QPen(Qt::transparent)); // Bordo trasparente
    setPos(x, y);
    this->wasserKonzentration = wasserKonzentration;
}

float WasserSimulationElement::holeWasserKonzentration() {
    return this->wasserKonzentration;
} 