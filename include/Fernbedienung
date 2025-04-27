#pragma once
#include <Hauptdisplay.h>
#include <string>
#include <stdbool>
#include <Fernbedienung-Interpreter.h>
#include <joystick2.h>
#include <joystick.h>
#include <ReturnHome.h>


using namespace std;
class SignalWandler {
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
