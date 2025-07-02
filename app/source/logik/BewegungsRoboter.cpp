#include "BewegungsRoboter.h"
#include "dcmotor.h"
#include "SignalTyp.h"
#include <iostream>
#include <cmath>
#define PI 3.14159265f
using namespace std;

BewegungsRoboter::BewegungsRoboter(float startx, float starty, float startwinkel)
    :x(startx), y(starty), Winkel(startwinkel) {}

void BewegungsRoboter::Empfangesignal(signaltyp Signal) {
    if (!roboterAktiv) {
        // Roboter ignoriert Signale wenn inaktiv
        stoppen();
        return;
    }
    
    switch(Signal) {
    case signaltyp::Vorvaerts:
        if (blockVorwaerts) {
            stoppen();
            break;
        }
        vorwaerts(0.8f);
        break;
    case signaltyp::Rueckwaerts:
        rueckwaerts(0.8f);
        break;
    case signaltyp::Rechts:
        drehenrechts(0.6f);
        break;
    case signaltyp::Links:
        drehenlinks(0.6f);
        break;
    case signaltyp::keine:
    default:
        stoppen();
        break;
    }
}

void BewegungsRoboter::vorwaerts(float leistung) {
    motorlinks.drehen(leistung,1);
    motorrechts.drehen(leistung,1);
}

void BewegungsRoboter::rueckwaerts(float leistung) {
    motorlinks.drehen(leistung,-1);
    motorrechts.drehen(leistung,-1);
}

void BewegungsRoboter::drehenlinks(float leistung) {
    motorlinks.drehen(leistung,-1);
    motorrechts.drehen(leistung,1);
}

void BewegungsRoboter::drehenrechts(float leistung){
    motorrechts.drehen(leistung,-1);
    motorlinks.drehen(leistung,1);
}

void BewegungsRoboter::stoppen() {
    motorlinks.stoppen();
    motorrechts.stoppen();
}

float BewegungsRoboter::gety() const {
    return y;
}

float BewegungsRoboter::getx() const {
    return x;
}

float BewegungsRoboter::getrichtung() const {
    return Winkel;
}

// Motor state getters for simulation
float BewegungsRoboter::getMotorLinksLeistung() const {
    return motorlinks.getLeistung();
}

float BewegungsRoboter::getMotorRechtsLeistung() const {
    return motorrechts.getLeistung();
}

int BewegungsRoboter::getMotorLinksRichtung() const {
    return motorlinks.getRichtung();
}

int BewegungsRoboter::getMotorRechtsRichtung() const {
    return motorrechts.getRichtung();
}

void BewegungsRoboter::setzeAktiv(bool aktiv) {
    roboterAktiv = aktiv;
    
    if (!aktiv) {
        // Roboter stoppen wenn deaktiviert
        stoppen();
    }
    
    std::cout << "BewegungsRoboter Status: " << (aktiv ? "Aktiv" : "Inaktiv") << std::endl;
}

void BewegungsRoboter::setzeBlockVorwaerts(bool blockiert) {
    blockVorwaerts = blockiert;
}



