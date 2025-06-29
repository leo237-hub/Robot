#pragma once
#include <QGraphicsEllipseItem>
#include "simulationElement.h"

/*
Zweck und Verhalten der WasserSimulationElement-Klasse:

Zweck: Erzeugt die Daten für Wasserquellen in der Umgebung.

Verhalten: Beinhaltet die Position der Wasserquelle und die aktuelle Wasser-Konzentration/Luftfeuchtigkeit. Diese Konzentration kann man sich von der Klasse ausgeben lassen.
Die Wasser-Konzentration kann mit der Zeit variieren, wie bei einer realen Wasserquelle.

*/

class WasserSimulationElement: public simulationElement {
private:
    float wasserKonzentration;

public:
    WasserSimulationElement(double x, double y, Qt::GlobalColor color = Qt::blue, bool solidStatus = false, double radius = 20.0, float wasserKonzentration = 80.0);
    float holeWasserKonzentration();
}; 