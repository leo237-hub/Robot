#include"Waermekamera.h"
#include "qdebug.h"
#include "qlogging.h"
#include <cstdlib>


WaermeKamera::WaermeKamera():aktiv(false){ }
WaermeKamera::~ WaermeKamera(){ }

bool WaermeKamera::wSchalten(){
    aktiv=!aktiv;
    return aktiv;
    qDebug() << "WaermeKamera wurde geschaltet.";
}
uint8_t* WaermeKamera::fotoMachen(uint8_t) const {
    const int breite = 640;
    const int hoehe = 480;
    const int groesse = breite * hoehe * 3;

    if (breite <= 0 || hoehe <= 0) return nullptr;

    uint8_t* data = new uint8_t[groesse];

    for (int i = 0; i < groesse; i += 3) {
        int temp = rand() % 256;

        data[i]     = temp;
        data[i + 1] = temp / 2;
        data[i + 2] = 0;
    }

    return data;
}
float WaermeKamera::temperaturLesen(){
    return 0;
}
uint8_t* WaermeKamera::videoAufnehmen(uint8_t bild [[maybe_unused]]) const {
    return 0;
}
