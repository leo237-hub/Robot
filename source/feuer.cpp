#include "feuer.h"
#include <QtMath>
#include <QBrush>

Feuer::Feuer(double x, double y, double radius,float temperatur) {
    setRect(0, 0, radius, radius);
    setBrush(Qt::red);
    setPos(x, y);
    this->Temperatur = temperatur;

}
float Feuer::holeTemperatur(){
    return this->Temperatur;
}

