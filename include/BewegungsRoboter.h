#pragma once
#include "dcmotor.h"
#include "../SignalTyp.h"

class BewegungsRoboter{
private:
    dcMotor motorlinks;
    dcMotor motorrechts;
    float x , y;
    float Winkel;
    void vorwaerts(float leistung = 1.0f);
    void rueckwaerts(float leistung = 1.0f);
    void drehenlinks(float leistung = 0.5f);
    void drehenrechts(float leistung = 0.5f);
    void stoppen();
public:
    BewegungsRoboter(float startx = 0.0f, float starty = 0.0f, float startwinkel = 0.0f);
    void Empfangeignal(signaltyp Signal);
    void Aktualisiereposition(float deltazeit);

    float getx() const;
    float gety() const;
    float getrichtung() const;

};
