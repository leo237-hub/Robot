#include <iostream>
#include "paketfach.h"
/*
void PaketFach::Oeffnen(){}
void PaketFach::Schliessen(){}


PaketFach::PaketFach() {}
PaketFach::~PaketFach() {}
*/

PaketFach::PaketFach() : zustand("GESCHLOSSEN") {
}

PaketFach::~PaketFach() = default;

/*
Öffnet das Paketfach
Ändert den Zustand nur wenn das Fach geschlossen ist
*/
void PaketFach::Oeffnen() {
    if (zustand == "GESCHLOSSEN") {
        zustand = "OFFEN";
    }
}

/*
Schließt das Paketfach
Ändert den Zustand nur wenn das Fach offen ist
*/
void PaketFach::Schliessen() {
    if (zustand == "OFFEN") {
        zustand = "GESCHLOSSEN";
    }
}

string PaketFach::holeZustand() const {
    return zustand;
}
