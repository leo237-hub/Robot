#include "feuer.h"
#include <QtMath>
#include <QBrush>

Feuer::Feuer(double x, double y,Qt::GlobalColor color,bool solidStatus, double radius,float temperatur)
    : simulationElement(x, y, color,solidStatus,radius), Temperatur(temperatur) {}


float Feuer::holeTemperatur() {
    return this->Temperatur;
}


