#include "Fernbedienung.h"
#include "SignalWandler.h"

/*
Konstruktor
Initialisiert die Fernbedienung mit ausgeschaltetem Controller und Roboter
*/
Fernbedienung::Fernbedienung() 
    : controllerOff(true)
    , robotOff(true) {
}

/*
Aktualisiert die Informationen auf dem Hauptdisplay
Zeigt Sensordaten, Kamerabilder und andere relevante Informationen an
*/
void Fernbedienung::DisplayinfoAktualisieren() {
    if (!controllerOff && !robotOff) {
        display.anzeigeAktualiesieren(0);
    }
}

/*
Verarbeitet Bewegungsbefehle vom ersten Joystick
Steuert die Kettenmotoren für Vorwärts/Rückwärts und Drehbewegungen
*/
void Fernbedienung::MotorBewegen() {
    if (!controllerOff && !robotOff) {
        stick1.Fahren();
    }
}

/*
Startet die Self-Check Funktion
Überprüft alle Sensoren und Aktoren auf Funktionsfähigkeit
*/
void Fernbedienung::SelfCheckStarten() {
    if (!controllerOff) {
        // Self-Check Logik wird hier implementiert
        // Kommunikation mit Selfcheck-Klasse
    }
}

/*
Öffnet oder schließt das Paketfach
Verwendet SignalWandler zur Kommunikation mit dem Paketfach
*/
void Fernbedienung::PaketFachOeffnen() {
    if (!controllerOff && !robotOff) {
        SignalWandler wandler;
        wandler.EmpfangeBefehlFernBedienung(4);
    }
}

/*
Steuert den Drehmotor für die Kopfbewegung
Ermöglicht das Drehen der Kameras und Sensoren
*/
void Fernbedienung::DremotorBewegen() {
    if (!controllerOff && !robotOff) {
        float winkel = 45.0f;
        stick2.WinkelAnpassen(winkel);
    }
}

void Fernbedienung::ausschalten() {
    controllerOff = true;
    robotOff = true;
    display.ausschalten();
}

void Fernbedienung::Anschalten() {
    controllerOff = false;
    display.einschalten();
}

/*
Hauptmethode zur Verarbeitung von Benutzereingaben
Liest Knopfzustände vom Interpreter und führt entsprechende Aktionen aus
*/
void Fernbedienung::verarbeiteEingabe(Fernbedienung_interpreter& interpreter) {
    if (controllerOff) {
        return;
    }
    
    Knopf* knoepfe = interpreter.leseKnoepfe();
    
    for (int i = 0; i < 6; i++) {
        if (interpreter.schickSignal(knoepfe[i])) {
            string knopfID = knoepfe[i].holeID();
            
            if (knopfID == "AN_AUS") {
                robotOff = !robotOff;
            } else if (knopfID == "RETURN_HOME" && !robotOff) {
                // Return Home Logik
            } else if (knopfID == "LAMPEN" && !robotOff) {
                // Lampen Toggle Logik
            } else if (knopfID == "AUDIO" && !robotOff) {
                // Audio Toggle Logik
            } else if (knopfID == "PAKETFACH") {
                PaketFachOeffnen();
            } else if (knopfID == "SELFCHECK") {
                SelfCheckStarten();
            }
        }
    }
    
    interpreter.resetAlleKnoepfe();
}

bool Fernbedienung::istControllerAn() const {
    return !controllerOff;
}

bool Fernbedienung::istRoboterAn() const {
    return !robotOff;
}

void Fernbedienung::setzeRoboterStatus(bool status) {
    robotOff = !status;
}