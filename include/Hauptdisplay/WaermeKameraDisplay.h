#pragma once

// Hier können Sie notwendige Standardbibliotheken einfügen
#include <iostream>

// Weitere notwendige Includes hier

// Beginn der Klassendefinition
class WaermekameraDisplay {  // Vererbung von Hauptdisplay

private:
// Membervariablen
    float WaermeBild;
    float MaximaleTemperatur;
    float MinimaleTemperatur;


    // Weitere Hilfsmethoden oder Membervariablen
public:
    // Konstruktoren
    WaermekameraDisplay(); // Standardkonstruktor
    // Destruktor
    virtual ~WaermekameraDisplay();


    // Methoden
    void waermeBildAnzeigen() const; // Beispiel für eine Methode
    void bildQualitätAnpassen() const;

};

