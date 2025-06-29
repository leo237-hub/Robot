#pragma once
#include "Hauptdisplay.h"
#include "FernbedienungInterpreter.h"
#include "joystick.h"
#include "joystick2.h"
#include "ReturnHome.h"
#include "SignalWandler.h"

using namespace std;

/*
Zweck und Verhalten der Fernbedienung-Klasse:

Zweck: Zentrale Steuerungseinheit für den ResQ-Roboter. Verwaltet alle Benutzereingaben und 
kommuniziert mit dem Roboter über verschiedene Schnittstellen.

Verhalten: Die Fernbedienung empfängt Eingaben über Knöpfe und Joysticks, interpretiert diese und 
sendet entsprechende Befehle an den Roboter. Sie verwaltet den Display für Anzeige von Sensordaten,
Videos und anderen Informationen. Die Klasse koordiniert zwischen Benutzereingaben und Robotersteuerung.
*/
class Fernbedienung {
private:
    HauptDisplay display;
    joystick stick1;
    joystick2 stick2;
    SignalWandler signalWandler;
    bool controllerOff;
    bool robotOff;
    
public:
    ReturnHome returner;
    
    Fernbedienung();
    ~Fernbedienung() = default;
    
    void DisplayinfoAktualisieren();
    void MotorBewegen();
    void SelfCheckStarten();
    void PaketFachOeffnen();
    void DremotorBewegen();
    void ausschalten();
    void Anschalten();
    void verarbeiteEingabe(FernbedienungInterpreter& interpreter);
    
    // Joystick Kommunikation
    void verarbeiteJoystick1Eingabe(float x, float y);
    void verarbeiteJoystick2Eingabe(float x, float y);
    
    bool istControllerAn() const;
    bool istRoboterAn() const;
    void setzeRoboterStatus(bool status);
};
