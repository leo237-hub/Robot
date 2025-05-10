#ifndef WÄRMEKAMERADISPLAY_H
#define WÄRMEKAMERADISPLAY_H

// Hier können Sie notwendige Standardbibliotheken einfügen
#include <iostream>

// Weitere notwendige Includes hier

// Beginn der Klassendefinition
class WärmekameraDisplay {  // Vererbung von Hauptdisplay

private:
// Membervariablen
    float WärmeBild;
    float MaximaleTemperatur;
    float MinimaleTemperatur;


    // Weitere Hilfsmethoden oder Membervariablen
public:
    // Konstruktoren
    WärmekameraDisplay(); // Standardkonstruktor
    // Destruktor
    virtual ~WärmekameraDisplay();


    // Methoden
    void WärmeBildAnzeigen() const; // Beispiel für eine Methode
    void BildQualitätAnpassen() const;

};

#endif // WÄRMEKAMERADISPLAY_H  