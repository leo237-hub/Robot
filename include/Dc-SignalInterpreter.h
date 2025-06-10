#pragma once
#include<iostream>
#include <string>
#include "SignalTyp.h"
using namespace std;
class Dc_SignalInterpreter {
    /*private:
        float Stromstaerke;
        float Spannung;
    */
public:
    //void Signalinterpretieren();
    signaltyp EingabeInterpretieren(const std::string & Eingabe);
};
