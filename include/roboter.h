#ifndef ROBOTER_H
#define ROBOTER_H
#include<iostream>
#include"dcmotor.h"
class roboter {
    dcMotor motorLinks;
    dcMotor motorRecht;
    //Position x,y-Richtung
    float x, y;
    // Richtung in Grad (0 = Rechts, 90 = oben, ...)
    float winkel;
public:
    roboter();
    ~roboter();
    void vorwaerts(float );
    void rueckwaerts(float );
    void drehenLinks(float );
    void drehenRechts(float winkelGrad);
    void stoppen();
    void aktualisierePosition(float deltazeit);
    float getx() const;
    float gety() const;
    float getRichtung();
};

#endif // ROBOTER_H
