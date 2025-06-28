#pragma once
#include <string>
#include "DreheSignalinterpreter.h"
#include "GpsSensor.h"
using namespace std;

class ReturnHome {
private:
    string Akkuzustand;
    GPSSensor Strecke;

public:
    string zurueckZurStation(GPSSensor Strecke);

};
