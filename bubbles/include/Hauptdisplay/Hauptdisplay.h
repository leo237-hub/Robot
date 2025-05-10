#ifndef HAUPTDISPLAY_H
#define HAUPTDISPLAY_H

// Hier können Sie notwendige Standardbibliotheken einfügen
#include <iostream>
using namespace std;

// Weitere notwendige Includes hier

// Beginn der Klassendefinition
class HauptDisplay {

private:

    int helligkeit;
    byte bild;
    string auflösung;
public:
    // Konstruktoren
    HauptDisplay();
    // Destruktor
    virtual ~ HauptDisplay();

    // Kopierkonstruktor und Zuweisungsoperator
    //MyClass(const MyClass& other); // Kopierkonstruktor
    //MyClass& operator=(const MyClass& other); // Zuweisungsoperator

    // Methoden
    void einschalten() const;

    void eusschalten() const;

    void AnzeigeAktualiesieren(byte* bild) const;

    void HelligkeitAnpassen(int helligkeit) const;

    // Getter und Setter nach Bedarf
    //int getValue() const;
    //void setValue(int value);


};

#endif //HAUPTDISPLAY_H 