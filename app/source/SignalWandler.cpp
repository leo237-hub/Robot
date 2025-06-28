#include "SignalWandler.h"
#include "paketfach.h"

/*
Konstruktor
Initialisiert den SignalWandler mit geschlossenem Paketfach
*/
SignalWandler::SignalWandler() 
    : paketfachOffen(false) {
}

/*
Empfängt und verarbeitet Befehle von der Fernbedienung
Parameter: gedrucktesKnopf - Index des gedrückten Knopfes
Rückgabe: String mit dem interpretierten Befehl
*/
string SignalWandler::EmpfangeBefehlFernBedienung(int gedrucktesKnopf) {
    string befehl;
    
    switch(gedrucktesKnopf) {
        case 0:
            befehl = "AN_AUS";
            break;
        case 1:
            befehl = "RETURN_HOME";
            break;
        case 2:
            befehl = "LAMPEN_TOGGLE";
            break;
        case 3:
            befehl = "AUDIO_TOGGLE";
            break;
        case 4:
            befehl = "PAKETFACH_TOGGLE";
            behandlePaketfachBefehl();
            break;
        case 5:
            befehl = "SELFCHECK";
            break;
        default:
            befehl = "UNBEKANNT";
            break;
    }
    
    fernbedienungsbefehl = befehl;
    return befehl;
}

/*
Private Methode zur Verwaltung des Paketfachs
Öffnet oder schließt das Paketfach je nach aktuellem Zustand
*/
void SignalWandler::behandlePaketfachBefehl() {
    static PaketFach paketfach;
    
    if (paketfachOffen) {
        paketfach.Schliessen();
        paketfachOffen = false;
    } else {
        paketfach.Oeffnen();
        paketfachOffen = true;
    }
}

/*
Sendet den aktuellen Systemstatus an die Fernbedienung
Rückgabe: Statusstring mit aktuellen Systeminformationen
*/
string SignalWandler::SendeStatusAnFernBedienung() {
    string status = "STATUS:";
    status += paketfachOffen ? "PAKETFACH_OFFEN" : "PAKETFACH_GESCHLOSSEN";
    return status;
}

/*
Sendet Sensordaten an die Fernbedienung
Rückgabe: Beispielwert für Sensordaten
*/
float SignalWandler::SendeSensordatenAnFernbedienung() {
    return 0.0f;
}

bool SignalWandler::istPaketfachOffen() const {
    return paketfachOffen;
}