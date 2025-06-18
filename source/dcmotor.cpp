#include<iostream>
#include<vector>
#include<QDebug>
#include "dcmotor.h"
#include "aktoren.h"
#include "ReturnHome.h"
#include "Dc-SignalInterpreter.h"
#include "selfcheck.h"
#include "roboter.h"

dcMotor::dcMotor()
    :Leistung(0.0f), Richtung(0) {}

void dcMotor:: drehen(float leistung, int richtung ) {
    // sicherstellen, dass die Richtung nur  -1, 0 oder 1 ist
    if(richtung < -1) {
        richtung = -1 ;
    }
    else if(richtung > 1) {
        richtung = 1;
    }
    //sicherstellen, das die Leistung nur  0.0 bis 1.0
    if(leistung < 0.0f) {
        leistung = 0.0f;
    }
    else if(leistung > 1.0f) {
        leistung = 1.0f;
    }
    Leistung = leistung;
    Richtung = richtung;
    //Ausgabe zur kontrole
    qDebug()<< "Drehen aktiviert:\n";
    qDebug()<<"Leistung = " << leistung << "\n";
    qDebug()<<"Richtung = ";
    if(richtung == 1){
        qDebug() << "Vorwaerts\n";
    }
    else if(richtung == -1){
        qDebug() << " Rueckwert\n";
    }
    else
        qDebug() << " Stopp\n";

}

void dcMotor:: stoppen() {
    Leistung = 0.0f;
    Richtung = 0;

    std::cout << " Motor gestoppt.\n";
}

float dcMotor::getLeistung() const {
    return Leistung;
}

int dcMotor::getRichtung() const {
    return Richtung;
}

dcMotor::~dcMotor() {}





