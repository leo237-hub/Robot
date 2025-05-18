#ifndef PAKETFACH_H
#define PAKETFACH_H
#include<string>
#include <iostream>
#include "SignalWandler.h"

using namespace std;
class PaketFach {
private:
    float flaesche;
    string Zustand;
public:
    PaketFach();
    ~PaketFach();
    void Oeffnen();
    void Schliessen();
};

#endif // PAKETFACH_H
