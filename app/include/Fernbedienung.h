
#pragma once
#include "Hauptdisplay.h"
#include <string>
#include "Fernbedienung-Interpreter.h"
#include "joystick.h"
#include "joystick2.h"
#include "ReturnHome.h"

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
    void verarbeiteEingabe(Fernbedienung_interpreter& interpreter);
    
    bool istControllerAn() const;
    bool istRoboterAn() const;
    void setzeRoboterStatus(bool status);
};
