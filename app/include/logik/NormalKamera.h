#pragma once
#include <cstdint>
using namespace std;

/*
Zweck und Verhalten der NormalKamera-Klasse

Zweck:
Repräsentiert eine normale Kamera zur Aufnahme von Fotos und Videos im Roboter.

Verhalten:
Ermöglicht das Ein- und Ausschalten, Aufnehmen von Fotos und Videos sowie das Setzen des Aktiv-Status.
*/

class NormalKamera {

private:
    int NummerID;
    int Auflösung;
    uint8_t bild;
    bool istAn;
public:
    NormalKamera();
    ~NormalKamera();
    bool schalten();
    uint8_t* videoAufnehmen(uint8_t bild) const;
    //void anzeigeAktualiesieren(uint8_t* bild) const;
    uint8_t*  fotoMachen(uint8_t bild) const;
    //int datenSchicken(uint8_t bild);
    void setAktiv(bool status);
};

