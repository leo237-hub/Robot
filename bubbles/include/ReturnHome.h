#pragma once
#include <string>
#include <DreheSignalinterpreter.h>
#include <sensor/GpsSensor.h>
using namespace std;

class ReturnHome {
private:
    string Akkuzustand;
    GPSSensor Strecke;

public:
    string ZurueckZurStation(GPSSensor Strecke);


};