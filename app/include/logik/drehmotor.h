#pragma once
#include "aktoren.h"
#include <vector>
#include "SignalTyp.h"

using namespace std;

// Forward declaration
class DreheSignalInterpreter;

/*
Zweck und Verhalten der Drehmotor-Klasse:

Zweck: Steuerung der Rotationsbewegung des Roboterkopfes.
Verwaltet die Drehung der Kameras und Sensoren.

Verhalten: Die Drehmotor-Klasse erbt von Aktoren und verwaltet die Rotationsgeschwindigkeit,
den aktuellen Winkel und die Leistung. Sie kann spezifische Winkel anfahren und die
Drehzahl einstellen.
*/
class Drehmotor : public Aktoren {
private:
    float MaxDrehzahl;
    float Aktuelwinkel;
    float Leistung;
    float Winkel;
    signaltyp aktuellerSignaltyp = signaltyp::keine;

public:
    Drehmotor();
    ~Drehmotor() override;
    
    float DrehWinkel(float Winkel); 
    float DrehZahl(float Zahl);     
    void Stoppen();
    
    // Getter-Methoden für Kommunikation mit DreheSignalInterpreter
    float getMaxDrehzahl() const;
    float getAktuellerWinkel() const;
    float getLeistung() const;
    float getWinkel() const;
    
    // Setter-Methoden
    void setzeAktuellerWinkel(float neuerWinkel);
    void setzeLeistung(float neueLeistung);
    void setzeSignaltyp(signaltyp sig);
};
