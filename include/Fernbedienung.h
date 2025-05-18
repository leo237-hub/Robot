#pragma once
#include "Hauptdisplay/Hauptdisplay.h"
#include <string>
#include "Fernbedienung-Interpreter.h"
#include "joystick.h"
#include "joystick2.h"
#include "ReturnHome.h"


using namespace std;

class Fernbedienung {
private:
    HauptDisplay Display;
    joystick stick1;
    joystick2 stick2;
    //Taster Taster Ist nicht im Klassendiagramm zu finden , steht aber als Attribut?
    bool ControllerOff;
    bool RobotOff;

public:
    ReturnHome Returner;
    void DisplayinfoAktualisieren();
    void MotorBewegen();
    void SelfCheckStarten();
    void PaketFachOeffnen();
    void DremotorBewegen();
    void ausschalten();
    void Anschalten();


};
