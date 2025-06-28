#pragma once
#include "Dc-SignalInterpreter.h"
#include "SignalTyp.h"

using namespace std;

/*
Zweck und Verhalten der joystick-Klasse:

Zweck: Steuerung der Bewegungsrichtung und Geschwindigkeit des Roboters über den ersten Joystick.
Verwaltet Vorwärts/Rückwärts und Links/Rechts Bewegungen des Roboters.

Verhalten: Die joystick-Klasse interpretiert Eingaben und wandelt diese in Winkel und Intensität um.
Sie kommuniziert mit dem Dc_SignalInterpreter für die Bewegungssteuerung und kann den aktuellen
Winkel und die Intensität abfragen und setzen.
*/
class joystick {
private:
    float winkel;
    float intensitaet;

public:
    Dc_SignalInterpreter interpreter;
    
    joystick();
    ~joystick() = default;
    
    void Fahren();
    void Halten();
    void setzeWinkel(float neuerWinkel);
    void setzeIntensitaet(float neueIntensitaet);
    float getWinkel() const;
    float getIntensitaet() const;
    
    // Kommunikation mit Fernbedienung
    signaltyp interpretiereBewegung() const;
    void verarbeiteJoystickEingabe(float x, float y);
};


