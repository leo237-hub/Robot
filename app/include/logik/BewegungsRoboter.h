#pragma once
#include "dcmotor.h"
#include "SignalTyp.h"
class BewegungsRoboter{
private:
    dcMotor motorlinks;
    dcMotor motorrechts;
    float x, y;
    float Winkel;
    bool roboterAktiv = true; // Roboter ist standardmäßig aktiv
    void vorwaerts(float leistung = 1.0f);
    void rueckwaerts(float leistung = 0.5f);
    void drehenlinks(float leistung = 0.5f);
    void drehenrechts(float leistung = 1.0f);
    void stoppen();
public:
    BewegungsRoboter(float startx = 0.0f, float starty = 0.0f, float startwinkel = 0.0f);
    void Empfangesignal(signaltyp Signal);
    void starten();
    float getx() const;
    float gety() const;
    float getrichtung() const;
    
    // Motor state getters for simulation
    float getMotorLinksLeistung() const;
    float getMotorRechtsLeistung() const;
    int getMotorLinksRichtung() const;
    int getMotorRechtsRichtung() const;
    
    // Methoden für Roboter-Status
    void setzeAktiv(bool aktiv);
    bool istAktiv() const { return roboterAktiv; }
};
