#include "DreheSignalinterpreter.h"

DreheSignalInterpreter::DreheSignalInterpreter() 
    : Stromstaerke(0.0f)
    , Spannung(0.0f)
    , drehmotor(nullptr) {
}

DreheSignalInterpreter::~DreheSignalInterpreter() = default;

void DreheSignalInterpreter::Signalinterpretieren() {
    // Interpretiert Rotationssignale für den Drehmotor
    // Hier würde die Logik für die Rotationssteuerung implementiert
}

/*
Setzt den Drehmotor für die Kommunikation
Parameter: motor - Pointer zum Drehmotor
*/
void DreheSignalInterpreter::setzeDrehmotor(Drehmotor* motor) {
    drehmotor = motor;
}

/*
Verarbeitet Rotationssignale basierend auf Winkel und Intensität
Parameter: winkel - Rotationswinkel in Grad, intensitaet - Rotationsintensität (0-100%)
*/
void DreheSignalInterpreter::verarbeiteRotation(float winkel, float intensitaet) {
    if (drehmotor && intensitaet > 10.0f) {
        // Aktiviere den Drehmotor
        drehmotor->Anschalten();
        
        // Setze die Rotationsgeschwindigkeit basierend auf Intensität
        float drehzahl = (intensitaet / 100.0f) * drehmotor->getMaxDrehzahl();
        drehmotor->DrehZahl(drehzahl);
        
        // Führe die Rotation aus
        rotiereKopf(winkel, intensitaet);
    } else if (drehmotor) {
        // Stoppe den Drehmotor bei zu geringer Intensität
        drehmotor->Stoppen();
    }
}

/*
Führt die eigentliche Kopfrotation aus
Parameter: winkel - Zielwinkel in Grad, intensitaet - Rotationsintensität
*/
void DreheSignalInterpreter::rotiereKopf(float winkel, float intensitaet) {
    if (drehmotor) {
        // Berechne die Rotationsrichtung und -geschwindigkeit
        float aktuellerWinkel = drehmotor->getAktuellerWinkel();
        float winkelDifferenz = winkel - aktuellerWinkel;
        
        // Normalisiere den Winkel
        if (winkelDifferenz > 180.0f) winkelDifferenz -= 360.0f;
        if (winkelDifferenz < -180.0f) winkelDifferenz += 360.0f;
        
        // Führe die Rotation aus
        float neuerWinkel = aktuellerWinkel + (winkelDifferenz * (intensitaet / 100.0f));
        drehmotor->DrehWinkel(neuerWinkel);
    }
} 