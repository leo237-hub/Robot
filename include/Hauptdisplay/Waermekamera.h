#pragma once
#include <iostream>
#include <cstdint>
using namespace std;

class WaermeKamera {

private:

    int IDNummer;
    float Temperator;  //Atributte solle groß oder klein geschrieben sein??
    int Aufloesung; // manschmal int und manschmal string ??
public:
    // Konstruktoren
    WaermeKamera();
    // Destruktor
    virtual ~ WaermeKamera();
    uint8_t* fotoMachen(uint8_t bild) const;

    float temperaturLesen();
    // Getter und Setter nach Bedarf
    //int getValue() const;
    //void setValue(int value);

    // Kopierkonstruktor und Zuweisungsoperator
    //MyClass(const MyClass& other); // Kopierkonstruktor
    //MyClass& operator=(const MyClass& other); // Zuweisungsoperator

    // Methoden
    uint8_t* videoAufnehmen(uint8_t bild) const;

};
