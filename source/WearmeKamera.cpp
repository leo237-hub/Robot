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
    const int width = 640;
    const int height = 480;
    const int size = width * height * 3;

    if (width <= 0 || height <= 0) return nullptr;

    uint8_t* data = new uint8_t[size];

    for (int i = 0; i < size; i += 3) {
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
uint8_t* WaermeKamera::videoAufnehmen(uint8_t bild) const {
    return 0;
}
