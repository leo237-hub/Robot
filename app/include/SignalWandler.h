#pragma once
#include <string>
#include "paketfach.h"
using namespace std;
class SignalWandler {
private:
    string sensorsignal;
    string Fernbedienungsbefehl;

public:

    string EmpfangeBefehlFernBedienung(int gedrucktesKnopf);
    string SendeStatusAnFernBedienung();
    float SendeSensordatenAnFernbedienung();

};
