#pragma once
#include "DreheSignalinterpreter.h"

using namespace std;

/*
Zweck und Verhalten der joystick2-Klasse:

Zweck: Steuerung der Kopfbewegung und Rotation des Roboters über den zweiten Joystick.
Verwaltet die Drehung des Roboterkopfes mit Kameras und Sensoren.

Verhalten: Die joystick2-Klasse interpretiert Eingaben und wandelt diese in Winkel und Intensität um.
Sie kommuniziert mit dem DreheSignalInterpreter für die Kopfrotationssteuerung und kann den aktuellen
Winkel und die Intensität abfragen und setzen.
*/
class joystick2 {
private:
    float winkel;
    float intensitaet;

public:
    DreheSignalInterpreter interpreter;
    
    joystick2();
    ~joystick2() = default;
    
    void WinkelAnpassen(float winkel);
    void setzeWinkel(float neuerWinkel);
    void setzeIntensitaet(float neueIntensitaet);
    float getWinkel() const;
    float getIntensitaet() const;
    
    // Kommunikation mit Fernbedienung
    void verarbeiteJoystickEingabe(float x, float y);
    float getRotationsWinkel() const;
};
