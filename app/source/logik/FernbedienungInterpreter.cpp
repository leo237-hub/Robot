#include "FernbedienungInterpreter.h"

/*
Konstruktor
Initialisiert alle Knöpfe mit ihren entsprechenden IDs
*/
FernbedienungInterpreter::FernbedienungInterpreter() {
    initialisiereKnoepfe();
}

/*
Private Methode zur Initialisierung der Knöpfe
Weist jedem Knopf eine eindeutige ID zu entsprechend der Anforderungen
*/
void FernbedienungInterpreter::initialisiereKnoepfe() {
    knoepfe[0] = Knopf(false, "AN_AUS");
    knoepfe[1] = Knopf(false, "RETURN_HOME");
    knoepfe[2] = Knopf(false, "LAMPEN");
    knoepfe[3] = Knopf(false, "AUDIO");
    knoepfe[4] = Knopf(false, "PAKETFACH");
    knoepfe[5] = Knopf(false, "SELFCHECK");
}

Knopf* FernbedienungInterpreter::leseKnoepfe() {
    return knoepfe.data();
}

bool FernbedienungInterpreter::schickSignal(Knopf& knopf) {
    return knopf.holeStatus();
}

/*
Setzt alle Knöpfe auf nicht-gedrückt zurück
Nützlich nach der Verarbeitung von Eingaben
*/
void FernbedienungInterpreter::resetAlleKnoepfe() {
    for (auto& knopf : knoepfe) {
        knopf.setzeStatus(false);
    }
}