#pragma once
#include "dcmotor.h"
#include "SignalTyp.h"
#include "DreheSignalinterpreter.h"

/*
Zweck und Verhalten der BewegungsRoboter-Klasse

Zweck:
Steuert die Bewegungen des Roboters durch Ansteuerung der Motoren und Umsetzung von Steuerbefehlen.

Verhalten:
Verarbeitet Steuerbefehle, setzt Motorleistung und Richtung, verwaltet den Status und die Position des Roboters.
*/

class BewegungsRoboter{
private:
    dcMotor motorlinks;
    dcMotor motorrechts;
    float x, y;
    float Winkel;
    bool roboterAktiv = true; 
    bool blockVorwaerts = false;
    DreheSignalInterpreter* drehInterpreter = nullptr;
    void vorwaerts(float leistung = 1.0f);
    void rueckwaerts(float leistung = 0.5f);
    void drehenlinks(float leistung = 0.5f);
    void drehenrechts(float leistung = 1.0f);
    void stoppen();
public:
    BewegungsRoboter(float startx = 0.0f, float starty = 0.0f, float startwinkel = 0.0f);
    void EmpfangeJoystick1(signaltyp Signal);
    void EmpfangeJoystick2(signaltyp Signal);
    void starten();
    float getx() const;
    float gety() const;
    float getrichtung() const;
    
    
    float getMotorLinksLeistung() const;
    float getMotorRechtsLeistung() const;
    int getMotorLinksRichtung() const;
    int getMotorRechtsRichtung() const;
    
    void setzeAktiv(bool aktiv);
    bool istAktiv() const { return roboterAktiv; }
    void setzeBlockVorwaerts(bool blockiert);
    void setzeDrehInterpreter(DreheSignalInterpreter* interpreter);
};
