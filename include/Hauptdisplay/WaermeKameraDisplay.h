#pragma once
#include <iostream>

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

