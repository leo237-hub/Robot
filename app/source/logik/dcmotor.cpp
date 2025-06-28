#include "dcmotor.h"
#include <iostream>

dcMotor::dcMotor() : Leistung(0.0f), Richtung(0) {}

void dcMotor::drehen(float leistung, int richtung) {
    this->Leistung = leistung;
    this->Richtung = richtung;
}

void dcMotor::stoppen() {
    Leistung = 0.0f;
    Richtung = 0;
}

float dcMotor::getLeistung() const {
    return Leistung;
}

int dcMotor::getRichtung() const {
    return Richtung;
}

dcMotor::~dcMotor() {}





