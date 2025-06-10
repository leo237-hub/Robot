#pragma once
#include <iostream>
using namespace std;
class NormalKamera {

private:
    int NummerID;
    int Auflösung;
    byte bild;
public:

    // Kopierkonstruktor und Zuweisungsoperator
    //MyClass(const MyClass& other); // Kopierkonstruktor
    //MyClass& operator=(const MyClass& other); // Zuweisungsoperator

    // Methoden
    byte* VideoAufnehmen(byte bild) const;            // soll const sein? was ist mit zeiger

    void AnzeigeAktualiesieren(byte* bild) const;            // soll const sein?

    byte*  FotoMachen(byte bild) const;               // soll const sein?

    int DatenSchicken(byte bild);

    // Getter und Setter nach Bedarf
    //int getValue() const;
    //void setValue(int value);
};

