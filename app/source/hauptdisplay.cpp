#include "Hauptdisplay.h"
#include <QDebug>   //qDebug statt std::
#include <cstdint>
#include <string>

HauptDisplay::HauptDisplay() {
    istAn =false;
    helligkeit=50;
    bild=0;
    aufloesung= "1920x1080"; // start werte
}

HauptDisplay::~HauptDisplay() {
}

void HauptDisplay::einschalten() {
    istAn =true;
    qDebug() << "Bildschirm wurde eingeschaltet.";  //qDebug = print "text" auf der GUI
}

void HauptDisplay::ausschalten() {
    istAn =false;
    qDebug() << "Bildschirm wurde ausgeschaltet.";
}

void HauptDisplay::anzeigeAktualiesieren(uint8_t neuesBild)  {
    bild = neuesBild;
    qDebug() << "Anzeige wurde aktualisiert. Neues Bild:" << static_cast<int>(bild);
    // unit8_t kann als Buchstabe geschrieben werden, deswegen schreiben wir static_cast<int> um ganzzahl zu bekommen "0_255"

}

bool HauptDisplay::isEingeschaltet() const {
    return istAn;
}
