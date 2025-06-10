#pragma once

// Hier können Sie notwendige Standardbibliotheken einfügen
#include <iostream>


// Weitere notwendige Includes hier

// Beginn der Klassendefinition
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

