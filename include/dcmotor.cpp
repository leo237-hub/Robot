#include<iostream>
#include<vector>
#include "dcmotor.h"
#include "aktoren.h"
#include "ReturnHome.h"
#include "Dc-SignalInterpreter.h"
#include "selfcheck.h"

dcMotor::dcMotor() {}
dcMotor::~dcMotor() {}

void dcMotor:: vorgehen() {
}

void dcMotor:: zuruektreten() {
}

void dcMotor:: stoppen() {
}

float dcMotor:: WinkelDrehen(float Winkel) {
    return Winkel;
}

float dcMotor:: Drehzahlaendern(float neueLeistung) {
    return neueLeistung;
}


