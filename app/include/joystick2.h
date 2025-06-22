#pragma once
#include "DreheSignalinterpreter.h"
using namespace std;
class joystick2 {
private:
    float winkel;
    float intensitaet;

public:
    DreheSignalInterpreter interpreter;
    void WinkelAnpassen(float winkel);


};
