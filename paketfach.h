#ifndef PAKETFACH_H
#define PAKETFACH_H
#include<string>
#include <iostream>
using namespace std;

class PaketFach
{
private:
    float flaesche;
    string Zustand;
public:
    void Oeffnen();
    void Schliessen();

    PaketFach(); // Konstruktor
    ~PaketFach(); //Destruktor
 };

#endif // PAKETFACH_H
