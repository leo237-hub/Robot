#pragma once
#include <string>
#include <paketfach.h>
using namespace std;
class SignalWandler {
private:
    string sensorsignal;
    string Fernbedienungsbefehl;
    PaketFach Fach;

public:
    string EmpfangeBefehlFernBedienung(Knopf gedrucktesKnopf);
    string SendeStatusAnFernBedienung();
    float SendeSensordatenAnFernbedienung();

};
