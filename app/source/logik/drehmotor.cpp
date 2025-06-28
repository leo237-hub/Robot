#include "drehmotor.h"
#include "aktoren.h"

/*
Konstruktor
Initialisiert den Drehmotor mit Standardwerten
*/
Drehmotor::Drehmotor() 
    : MaxDrehzahl(360.0f)  // 360 Grad pro Sekunde
    , Aktuelwinkel(0.0f)
    , Leistung(0.0f)
    , Winkel(0.0f) {
}

/*
Destruktor
*/
Drehmotor::~Drehmotor() = default;

/*
Dreht den Motor auf einen bestimmten Winkel
Parameter: Winkel - Zielwinkel in Grad
Rückgabe: Aktueller Winkel nach der Rotation
*/
float Drehmotor::DrehWinkel(float neuerWinkel) {
    if (neuerWinkel >= 0.0f && neuerWinkel <= 360.0f) {
        Winkel = neuerWinkel;
        Aktuelwinkel = neuerWinkel;
    }
    return Aktuelwinkel;
}

/*
Stellt die Drehzahl ein
Parameter: Zahl - Neue Drehzahl in Grad pro Sekunde
Rückgabe: Aktuelle Drehzahl
*/
float Drehmotor::DrehZahl(float Zahl) {
    if (Zahl >= 0.0f && Zahl <= MaxDrehzahl) {
        Leistung = Zahl;
    }
    return Leistung;
}

/*
Stoppt die Rotation des Motors
*/
void Drehmotor::Stoppen() {
    Leistung = 0.0f;
    ausschalten();
}

/*
Getter-Methoden für Kommunikation mit DreheSignalInterpreter
*/
float Drehmotor::getMaxDrehzahl() const {
    return MaxDrehzahl;
}

float Drehmotor::getAktuellerWinkel() const {
    return Aktuelwinkel;
}

float Drehmotor::getLeistung() const {
    return Leistung;
}

float Drehmotor::getWinkel() const {
    return Winkel;
}

/*
Setter-Methoden
*/
void Drehmotor::setzeAktuellerWinkel(float neuerWinkel) {
    if (neuerWinkel >= 0.0f && neuerWinkel <= 360.0f) {
        Aktuelwinkel = neuerWinkel;
    }
}

void Drehmotor::setzeLeistung(float neueLeistung) {
    if (neueLeistung >= 0.0f && neueLeistung <= MaxDrehzahl) {
        Leistung = neueLeistung;
    }
}
