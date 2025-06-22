#pragma once
#include <QGraphicsEllipseItem>
#include "simulationElement.h"


/*
Zweck und Verhalten der Feuerklasse:

Zweck: Erzeugt die Daten fuer den Feuer in der Umgebung.

Verhalten: Beinhaltet die Position des Feuer und die aktuelle Temperatur. Diese Temperatur kann man sich von der Klasse ausgeben lassen.
Die Temperatur geht mit der Zeit runter,wie bei einen normalen Feuer.

*/

class Feuer: public simulationElement {
private:

    float Temperatur;
public:

    Feuer(double x, double y, Qt::GlobalColor color = Qt::red,bool solidStatus = false,double radius = 20.0,float Temperatur = 100);
    float holeTemperatur();
};
