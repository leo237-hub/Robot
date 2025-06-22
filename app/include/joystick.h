#pragma once
#include "Dc-SignalInterpreter.h"
using namespace std;
class joystick {
private:
    float winkel;
    float intensitaet;

public:
    Dc_SignalInterpreter interpreter;
    void Fahren();
    void Halten();


};


