#ifndef WÄRMEKAMERA_H
#define WÄRMEKAMERA_H

// Hier können Sie notwendige Standardbibliotheken einfügen
#include <iostream>
using namespace std;


// Beginn der Klassendefinition
class WärmeKamera {

private:

    int IDNummer;
    float Temperator;  //Atributte solle groß oder klein geschrieben sein??
    int Auflösung; // manschmal int und manschmal string ??
public:
    // Konstruktoren
    WärmeKamera();
    // Destruktor
    virtual ~ WärmeKamera();

    // Kopierkonstruktor und Zuweisungsoperator
    //MyClass(const MyClass& other); // Kopierkonstruktor
    //MyClass& operator=(const MyClass& other); // Zuweisungsoperator

    // Methoden
    byte* VideoAufnehmen(byte bild) const;

    byte*  FotoMachen(byte bild) const;

    int TemperaturLesen();
    // Getter und Setter nach Bedarf
    //int getValue() const;
    //void setValue(int value);


};

#endif //WÄRMEKAMERA_H 