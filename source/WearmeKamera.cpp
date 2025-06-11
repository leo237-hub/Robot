#include"Waermekamera.h"


WaermeKamera::WaermeKamera():istAn(false){ }

WaermeKamera::~ WaermeKamera(){ }


uint8_t* WaermeKamera::fotoMachen(uint8_t bild) const{
    return 0;

}
float WaermeKamera::temperaturLesen(){
    return 0;
}
uint8_t* WaermeKamera::videoAufnehmen(uint8_t bild) const {
    return 0;
}

bool WaermeKamera::wSchalten(){
    istAn=!istAn;
    return istAn;
}
