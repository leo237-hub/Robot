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
Steuert die Kettenmotoren für Vorwärts/Rückwärts und Links/Rechts Bewegungen des Roboters
*/
void Fernbedienung::MotorBewegen() {
    if (!controllerOff && !robotOff) {
        // Joystick1 kommuniziert mit Fernbedienung (Bewegungssteuerung)
        signaltyp bewegung = stick1.interpretiereBewegung();
        
        // Fernbedienung kommuniziert mit Dc_SignalInterpreter
        string bewegungsSignal;
        switch(bewegung) {
            case signaltyp::Vorvaerts:
                bewegungsSignal = "w";
                break;
            case signaltyp::Rueckwaerts:
                bewegungsSignal = "s";
                break;
            case signaltyp::Links:
                bewegungsSignal = "a";
                break;
            case signaltyp::Rechts:
                bewegungsSignal = "d";
                break;
            default:
                bewegungsSignal = "";
                break;
        }
        
        // Dc_SignalInterpreter kommuniziert mit DC Motor
        if (!bewegungsSignal.empty()) {
            stick1.interpreter.EingabeInterpretieren(bewegungsSignal);
        }
        
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
        signalWandler.EmpfangeBefehlFernBedienung(4);
    }
}

/*
Steuert den Drehmotor für die Kopfbewegung
Ermöglicht das Drehen des Roboterkopfes mit Kameras und Sensoren
*/
void Fernbedienung::DremotorBewegen() {
    if (!controllerOff && !robotOff) {
        // Joystick2 kommuniziert mit Fernbedienung (Kopfrotationssteuerung)
        float rotationsWinkel = stick2.getRotationsWinkel();
        
        // Fernbedienung kommuniziert mit DreheSignalInterpreter
        stick2.WinkelAnpassen(rotationsWinkel);
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
void Fernbedienung::verarbeiteEingabe(FernbedienungInterpreter& interpreter) {
    if (controllerOff) {
        return;
    }
    
    Knopf* knoepfe = interpreter.leseKnoepfe();
    
    for (int i = 0; i < 6; i++) {
        if (interpreter.schickSignal(knoepfe[i])) {
            string knopfID = knoepfe[i].holeID();
            
            if (knopfID == "AN_AUS") {
                robotOff = !robotOff;
                if(robotOff){
                    ausschalten();
                }
                else{
                    Anschalten();
                }
            } else if (knopfID == "RETURN_HOME" && !robotOff) {
                // Return Home Logik
            } else if (knopfID == "LAMPEN" && !robotOff) {
                // Lampen ein/aus schalten
                signalWandler.EmpfangeBefehlFernBedienung(2);
            } else if (knopfID == "AUDIO" && !robotOff) {
                // Audio ein/aus schalten
                signalWandler.EmpfangeBefehlFernBedienung(3);
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

/*
Verarbeitet Eingaben vom ersten Joystick (Bewegungssteuerung)
Parameter: x - X-Koordinate (-1.0 bis 1.0), y - Y-Koordinate (-1.0 bis 1.0)
*/
void Fernbedienung::verarbeiteJoystick1Eingabe(float x, float y) {
    if (!controllerOff && !robotOff) {
        // Joystick1 verarbeitet die Eingabe (Roboterbewegung)
        stick1.verarbeiteJoystickEingabe(x, y);
        
        // Fernbedienung leitet die Bewegung weiter
        MotorBewegen();
    }
}

/*
Verarbeitet Eingaben vom zweiten Joystick (Kopfrotationssteuerung)
Parameter: x - X-Koordinate (-1.0 bis 1.0), y - Y-Koordinate (-1.0 bis 1.0)
*/
void Fernbedienung::verarbeiteJoystick2Eingabe(float x, float y) {
    if (!controllerOff && !robotOff) {
        // Joystick2 verarbeitet die Eingabe (Kopfrotation)
        stick2.verarbeiteJoystickEingabe(x, y);
        
        // Fernbedienung leitet die Kopfrotation weiter
        DremotorBewegen();
    }
}