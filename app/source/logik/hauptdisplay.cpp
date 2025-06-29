#include "Hauptdisplay.h"
#include <QDebug>
#include <cstdint>
#include <string>

HauptDisplay::HauptDisplay() {
    istAn = false;
    helligkeit = 50;
    bild = 0;
    aufloesung = "1920x1080"; // Startwerte
}

HauptDisplay::~HauptDisplay() {
}

void HauptDisplay::einschalten() {
    istAn = true;
    qDebug() << "Bildschirm wurde eingeschaltet.";
}

void HauptDisplay::ausschalten() {
    istAn = false;
    qDebug() << "Bildschirm wurde ausgeschaltet.";
}

void HauptDisplay::anzeigeAktualiesieren(uint8_t neuesBild) {
    bild = neuesBild;
    qDebug() << "Anzeige wurde aktualisiert. Neues Bild:" << static_cast<int>(bild);
}

void HauptDisplay::helligkeitAnpassen(int neueHelligkeit) {
    helligkeit = neueHelligkeit;
    qDebug() << "Helligkeit wurde angepasst auf:" << helligkeit;
}

bool HauptDisplay::istEingeschaltet() const {
    return istAn;
} 