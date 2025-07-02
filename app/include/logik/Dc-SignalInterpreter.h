#pragma once
#include<iostream>
#include <string>
#include "SignalTyp.h"
using namespace std;

/*
Zweck und Verhalten der Dc_SignalInterpreter-Klasse

Zweck:
Interpretiert Steuersignale für Gleichstrommotoren und wandelt Eingaben in Steuerbefehle um.

Verhalten:
Analysiert Eingabestrings und gibt entsprechende Signaltypen für die Motorsteuerung zurück.
*/

class Dc_SignalInterpreter {
    /*private:
        float Stromstaerke;
        float Spannung;
    */
public:
    //void Signalinterpretieren();
    signaltyp EingabeInterpretieren(const std::string & Eingabe);
};
