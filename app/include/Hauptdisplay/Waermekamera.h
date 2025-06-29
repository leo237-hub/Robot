#pragma once
#include <cstdint>
using namespace std;

class WaermeKamera {
private:

    int IDNummer;
    float Temperatur;
    float Aufloesung;
    bool aktiv;
public:
    WaermeKamera();
    virtual ~ WaermeKamera();

    bool wSchalten();
    uint8_t* fotoMachen(uint8_t bild) const;
    float temperaturLesen();
    uint8_t* videoAufnehmen(uint8_t bild) const;
    bool istAktiv()const {return aktiv;}
};
