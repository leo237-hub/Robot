#pragma once

#include <iostream>
#include <cstdint>
using namespace std;
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

