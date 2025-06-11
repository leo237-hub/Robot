#include"NormalKamera.h"


NormalKamera::NormalKamera():istAn(false) {}
NormalKamera::~NormalKamera(){}


bool NormalKamera:: schalten(){
    istAn=!istAn;
    return istAn;
}
uint8_t* NormalKamera::videoAufnehmen(uint8_t bild) const{
    return fotoMachen(bild);
}


//void NormalKamera::anzeigeAktualiesieren(uint8_t* bild)const{}


uint8_t*  NormalKamera::fotoMachen(uint8_t bild)const{
    int width = 640;
    int height = 480;
    int size = height * width *3;

    uint8_t* data = new uint8_t[size];

    for (int i =0 ; i< size; i +=3){
        data[i]= rand()%256;
        data[i +1]= rand()%256;
        data[i +2]= rand()%256;
    }
    return data;
}
//int NormalKamera::datenSchicken(uint8_t bild){}
void NormalKamera::setAktiv(bool status){
    istAn = status;
}
