#include "BewegungsRoboter.h"
#include"roboter.h"
#include <iostream>
#include <cmath>
#include<QDebug>
#define PI 3.14159265f
using namespace std;
BewegungsRoboter::BewegungsRoboter(float startx, float starty, float startwinkel)
    :x(startx), y(starty), Winkel(startwinkel) {}

void BewegungsRoboter::Empfangesignal(signaltyp Signal) {
    switch(Signal) {
    case signaltyp::Vorvaerts:
        vorwaerts(1.0f);
        break;
    case signaltyp::Rueckwaerts:
        rueckwaerts(1.0f);
        break;
    case signaltyp::Rechts:
        drehenrechts(0.5f);
        break;
    case signaltyp::Links:
        drehenlinks(0.5f);
        break;
    case signaltyp::keine:
    default:
        stoppen();
        break;
    }
}

/* Die methode implementiert die bewegung und Drehung eines Motors.
 * EffektivLeistung: Motor vorwärt läuft (Richtung = 1), bleibt der Wert +
 * wenn Rückwärts(-1), ist die Leeistung - =>zeigt dass sich der Motor in entgegengesetzte Richtung dreht.
 * Geschwindigkeit : Wenn beide gleich sind → fährt der Roboter geradeaus,Wenn unterschiedlich → er dreht.
 * Drehung: Dreheffekt, Wenn rechts > links → der Roboter dreht sich nach links.Umgekehrt → nach rechts.
 * Der Winkel (Richtung des Roboters) wird um die Drehung pro Zeit aktualisiert.
*/

//Diese Methode soll in die Simulationsumgebung sein!!!
void BewegungsRoboter::Aktualisiereposition(float deltazeit){
    float effektiveLeistungRechts = motorrechts.getLeistung() * motorrechts.getRichtung();
    float effektiveLeistungLinks = motorlinks.getLeistung()  * motorlinks.getRichtung();
    float geschwindigkeit = (effektiveLeistungLinks + effektiveLeistungRechts) / 2.0f;
    float drehung = (effektiveLeistungRechts - effektiveLeistungLinks) * 50.0f;
    //Winkel aktualisiesren
    Winkel += drehung * deltazeit;
    if (Winkel >= 360.0f) Winkel -= 360.0f;
    if (Winkel < 0.0f)    Winkel += 360.0f;
    // Bewegung entlang der Aktuellen Richtung muss in Simulation sein
    float rad = Winkel * PI / 180.0f;
    x += std::cos(rad) * geschwindigkeit * deltazeit;
    y += std::sin(rad) * geschwindigkeit * deltazeit;
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
    qDebug() << " Links \n";
}

void BewegungsRoboter::drehenrechts(float leistung){
    motorrechts.drehen(leistung,-1);
    motorlinks.drehen(leistung,1);
    qDebug() << "Recht \n";
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



