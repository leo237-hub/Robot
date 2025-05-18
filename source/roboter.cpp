#include <iostream>
#include <cmath>
#include "../include/roboter.h"
#include "../include/dcmotor.h"

#define PI 3.14159265f

/*
roboter::roboter()
    :x(0.0f), y(0.0f), winkel(0.0f){}
roboter::~roboter(){}

void roboter::vorwaerts(float leistung) {
    motorLinks.drehen(leistung, 1);
    motorRecht.drehen(leistung, 1);
}

void roboter::rueckwaerts(float leistung){
    motorLinks.drehen(leistung, -1);
    motorRecht.drehen(leistung, -1);
}

void roboter::drehenLinks(float leistung){
    motorLinks.drehen(leistung, -1);
    motorRecht.drehen(leistung,  1);
}

void roboter::drehenRechts(float leistung){
    motorLinks.drehen(leistung,  1);
    motorRecht.drehen(leistung, -1);
}

void roboter::stoppen() {
    motorLinks.stoppen();
    motorRecht.stoppen();
}
*/

/* Die methode simuliert die bewegung und Drehung eines Motors.
 * EffektivLeistung: Motor vorwärt läuft (Richtung = 1), bleibt der Wert +
 * wenn Rückwärts(-1), ist die Leeistung - =>zeigt dass sich der Motor in entgegengesetzte Richtung dreht.
 * Geschwindigkeit : Wenn beide gleich sind → fährt der Roboter geradeaus,Wenn unterschiedlich → er dreht.
 * Drehung: Dreheffekt, Wenn rechts > links → der Roboter dreht sich nach links.Umgekehrt → nach rechts.
 * Der Winkel (Richtung des Roboters) wird um die Drehung pro Zeit aktualisiert.
*/
/*
void roboter::aktualisierePosition(float deltazeit) {
    float effektiveLeistungLinks = motorLinks.getLeistung() * motorLinks.getRichtung();
    float effektiveLeistungRechts = motorRechts.getLeistung() * motorRechts.getRichtung();
    float geschwindigkeit = (effektiveLeistungLinks + effektiveLeistungRechts) / 2.0f;
    // Drehrate-skalierung, 50.0f ist ein Faktor, der den Dreheffekt verstärkt (kann angepasst werden je nach Modell)
    float Drehung = (effektiveLeistungRecht - effektiveLeistungLinks) * 50.0f;
    //Richtung aktualisieren
    winkel += Drehung * deltaZeit;
    if (winkel >= 360.0f) winke -= 360.0f;
    if ( winke< 0.0f)    winke += 360.0f;

    // Neue Position berechnen: Basierend auf die Richtung,Geschwindigkeit und vergangener Zeit
    float rad = winkel * PI / 180.0f;
    x += std::cos(rad) * geschwindigkeit * deltaZeit;
    y += std::sin(rad) * geschwindigkeit * deltaZeit;
    std::cout <<"[Roboter] neue Position : (" << x << "," << y << "), Richtung: "<< winkel <<"°\n";
}
float roboter::getx() const {
    return x ;
}

float roboter::gety() const {
    return y ;
}

float roboter::getRichtung() {
    reuturn winkel;
}
*/
#include <QBrush>

Roboter::Roboter(double x, double y, double radius) {
    setRect(0, 0, radius, radius);
    setBrush(Qt::blue);
    setPos(x, y);
}

QPointF Roboter::getCenterPosition() const {
    return scenePos() + rect().center();
}

