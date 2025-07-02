#pragma once
#include "dcmotor.h"
#include "SignalTyp.h"

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
    bool roboterAktiv = true; // Roboter ist standardmäßig aktiv
    bool blockVorwaerts = false;
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
    void setzeBlockVorwaerts(bool blockiert);
};
