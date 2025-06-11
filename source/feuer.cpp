#include "feuer.h"
#include <QtMath>
#include <QBrush>

<<<<<<< Updated upstream
Feuer::Feuer(double x, double y,Qt::GlobalColor color,bool solidStatus, double radius,float temperatur)
    : simulationElement(x, y, color,solidStatus,radius), Temperatur(temperatur) {}


float Feuer::holeTemperatur() {
=======
Feuer::Feuer(double x, double y, double radius,float temperatur){
    setRect(0, 0, radius, radius);
    setBrush(Qt::red);
    setPos(x, y);
    this->Temperatur = temperatur;
}
float Feuer::holeTemperatur(){
>>>>>>> Stashed changes
    return this->Temperatur;
}


