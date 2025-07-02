#pragma once
#include "drehmotor.h"

using namespace std;

/*
Zweck und Verhalten der DreheSignalInterpreter-Klasse:

Zweck: Interpretation von Rotationssignalen und Kommunikation mit dem Drehmotor.
Verwaltet die Übersetzung von Joystick-Eingaben in Rotationsbefehle.

Verhalten: Die DreheSignalInterpreter-Klasse empfängt Winkel und Intensität vom Joystick2,
interpretiert diese und sendet entsprechende Befehle an den Drehmotor für die Kopfrotation.
*/
class DreheSignalInterpreter {
private:
    float Stromstaerke;
    float Spannung;
    Drehmotor* drehmotor;

public:
    DreheSignalInterpreter();
    virtual ~DreheSignalInterpreter();
    void Signalinterpretieren();
    
    void setzeDrehmotor(Drehmotor* motor);
    void verarbeiteRotation(float winkel, float intensitaet);
    void rotiereKopf(float winkel, float intensitaet);
    void drehenLinks();
    void drehenRechts();
    void aktiviereDrehmotor(float leistung);
};


