#include "feuer.h"
#include <QtMath>
#include <QBrush>
#include <QPen>


Feuer::Feuer(double x, double y,Qt::GlobalColor color,bool solidStatus, double radius,float temperatur)
    : simulationElement(x, y, color,solidStatus,radius), Temperatur(temperatur) {
    
    setRect(0, 0, 1.5*radius, 1.5*radius);
    setBrush(Qt::transparent);
    setPen(QPen(Qt::transparent));
    setPos(x, y);
    this->Temperatur = temperatur;
}


/*
Feuer::Feuer(double x, double y, double radius,float temperatur){
    setRect(0, 0, radius, radius);
    setBrush(Qt::red);
    setPos(x, y);
    this->Temperatur = temperatur;
} */
float Feuer::holeTemperatur(){
    return this->Temperatur;
}


