#pragma once
#include <QGraphicsEllipseItem>
#include "simulationElement.h"

/*
Zweck und Verhalten der GasSimulationElement-Klasse:

Zweck: Erzeugt die Daten für Gasquellen in der Umgebung.

Verhalten: Beinhaltet die Position der Gasquelle und die aktuelle Gas-Konzentration. Diese Konzentration kann man sich von der Klasse ausgeben lassen.
Die Gas-Konzentration kann mit der Zeit variieren, wie bei einer realen Gasquelle.

*/

class GasSimulationElement: public simulationElement {
private:
    float gasKonzentration;

public:
    GasSimulationElement(double x, double y, Qt::GlobalColor color = Qt::yellow, bool solidStatus = false, double radius = 20.0, float gasKonzentration = 50.0);
    float holeGasKonzentration();
}; 