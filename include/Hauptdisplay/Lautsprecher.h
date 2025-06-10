#pragma once
#include <iostream>

class Lautsprecher  { // Vererbung von Aktoren

private:
// Membervariablen
    int Lautstaerke;
    bool Starus; //bolean ist nicht definiert
    float TonFrequenz;


    // Weitere Hilfsmethoden oder Membervariablen
public:
    // Konstruktoren
    Lautsprecher(); // Standardkonstruktor
    // Destruktor
    virtual ~Lautsprecher();


    // Methoden
    void spracheAusgeben() const; // Beispiel für eine Methode
    void lautStaerkeAnpassen() const;

};

