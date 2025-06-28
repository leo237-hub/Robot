#include "Fernbedienung-Interpreter.h"

/*
Konstruktor
Initialisiert alle Knöpfe mit ihren entsprechenden IDs
*/
Fernbedienung_interpreter::Fernbedienung_interpreter() {
    initialisiereKnoepfe();
}

/*
Private Methode zur Initialisierung der Knöpfe
Weist jedem Knopf eine eindeutige ID zu entsprechend der Anforderungen
*/
void Fernbedienung_interpreter::initialisiereKnoepfe() {
    knoepfe[0] = Knopf(false, "AN_AUS");
    knoepfe[1] = Knopf(false, "RETURN_HOME");
    knoepfe[2] = Knopf(false, "LAMPEN");
    knoepfe[3] = Knopf(false, "AUDIO");
    knoepfe[4] = Knopf(false, "PAKETFACH");
    knoepfe[5] = Knopf(false, "SELFCHECK");
}

Knopf* Fernbedienung_interpreter::leseKnoepfe() {
    return knoepfe.data();
}

bool Fernbedienung_interpreter::schickSignal(Knopf& knopf) {
    return knopf.holeStatus();
}

/*
Setzt alle Knöpfe auf nicht-gedrückt zurück
Nützlich nach der Verarbeitung von Eingaben
*/
void Fernbedienung_interpreter::resetAlleKnoepfe() {
    for (auto& knopf : knoepfe) {
        knopf.setzeStatus(false);
    }
}