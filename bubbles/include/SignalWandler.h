#pragma once
#include <string>
#include <PaketFach>
using namespace std;
class SignalWandler {
    private:
    string sensorsignal;
    string Fernbedienungsbefehl;

    public:
    PaketFach Fach;
    string EmpfangeBefehlFernBedienung(Knopf gedrucktesKnopf);
    string SendeStatusAnFernBedienung();
    float SendeSensordatenAnFernbedienung();

};
