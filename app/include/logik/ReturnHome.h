#pragma once
#include <string>
#include "DreheSignalinterpreter.h"
#include "GpsSensor.h"
using namespace std;

/*
Zweck und Verhalten der ReturnHome-Klasse

Zweck:
Ermöglicht dem Roboter die Rückkehr zur Basisstation, z.B. bei niedrigem Akkustand.

Verhalten:
Verwendet GPS-Daten und Akkuzustand, um die Rückkehr zur Station zu steuern und die Strecke zu berechnen.
*/

class ReturnHome {
private:
    string Akkuzustand;
    GPSSensor Strecke;

public:
    string zurueckZurStation(GPSSensor Strecke);

};
