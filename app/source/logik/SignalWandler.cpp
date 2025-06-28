#include "SignalWandler.h"
#include "paketfach.h"
#include "lampe.h"
#include "Lautsprecher.h"

/*
Konstruktor
Initialisiert den SignalWandler mit geschlossenem Paketfach, ausgeschalteten Lampen und ausgeschaltetem Audio
*/
SignalWandler::SignalWandler() 
    : paketfachOffen(false)
    , lampenAn(false)
    , audioAn(false) {
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
            befehl = "LAMPEN";
            behandleLampenBefehl();
            break;
        case 3:
            befehl = "AUDIO";
            behandleAudioBefehl();
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
Private Methode zur Verwaltung der Lampen
Schaltet die Lampen ein oder aus je nach aktuellem Zustand
*/
void SignalWandler::behandleLampenBefehl() {
    static Lampe lampe;
    
    if (lampenAn) {
        lampe.ausschalten();
        lampenAn = false;
    } else {
        lampe.einschalten();
        lampenAn = true;
    }
}

/*
Private Methode zur Verwaltung des Audios
Schaltet die Lautsprecher ein oder aus je nach aktuellem Zustand
*/
void SignalWandler::behandleAudioBefehl() {
    static Lautsprecher lautsprecher;
    
    if (audioAn) {
        lautsprecher.ausschalten();
        audioAn = false;
    } else {
        lautsprecher.einschalten();
        audioAn = true;
    }
}

/*
Sendet den aktuellen Systemstatus an die Fernbedienung
Rückgabe: Statusstring mit aktuellen Systeminformationen
*/
string SignalWandler::SendeStatusAnFernBedienung() {
    string status = "STATUS:";
    status += paketfachOffen ? "PAKETFACH_OFFEN" : "PAKETFACH_GESCHLOSSEN";
    status += ",";
    status += lampenAn ? "LAMPEN_AN" : "LAMPEN_AUS";
    status += ",";
    status += audioAn ? "AUDIO_AN" : "AUDIO_AUS";
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

bool SignalWandler::sindLampenAn() const {
    return lampenAn;
}

bool SignalWandler::istAudioAn() const {
    return audioAn;
}