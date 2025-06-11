#pragma once
#include <iostream>
#include <cstdint>
using namespace std;

class WaermeKamera {

private:

    int IDNummer;
    float Temperator;
    float Aufloesung;
    bool istAn;
public:
    WaermeKamera();

    virtual ~ WaermeKamera();
    bool wSchalten();
    uint8_t* fotoMachen(uint8_t bild) const;
    float temperaturLesen();
    uint8_t* videoAufnehmen(uint8_t bild) const;

};
