#include <QBrush>
#include <iostream>
#include <cmath>
<<<<<<< HEAD
#include <string>
#include "../include/roboter.h"
#include "../include/dcmotor.h"
#include "../include/Dc-SignalInterpreter.h"
=======
#include "roboter.h"
#include "dcmotor.h"
#include <QBrush>
>>>>>>> d7bc28e2aa29386f15a438312a94ab71a5dd378c
#define PI 3.14159265f
using namespace std;

Roboter::Roboter(double x, double y, double radius)
    : x(x), y(y), winkel(30.0f) {
    setRect(0, 0, radius, radius);
    setBrush(Qt::blue);
    //Drehung um Mittelpunkt
    setTransformOriginPoint(rect().center());
    //Startposition
    setPos(x, y);
}

Roboter::~Roboter(){}

void Roboter::vorwaerts(float leistung){
    motorLinks.drehen(leistung, 1);
    motorRechts.drehen(leistung, 1);
}

void Roboter::rueckwaerts(float leistung){
    motorLinks.drehen(leistung, -1);
    motorRechts.drehen(leistung, -1);
}

void Roboter::drehenLinks(float leistung){
    motorLinks.drehen(leistung, -1);
    motorRechts.drehen(leistung, 1);
}

void Roboter::drehenRechts(float leistung){
    motorLinks.drehen(leistung, 1);
    motorRechts.drehen(leistung, -1);
}

void Roboter::stoppen(){
    motorLinks.stoppen();
    motorRechts.stoppen();
}

/* Die methode implementiert die bewegung und Drehung eines Motors.
 * EffektivLeistung: Motor vorwärt läuft (Richtung = 1), bleibt der Wert +
 * wenn Rückwärts(-1), ist die Leeistung - =>zeigt dass sich der Motor in entgegengesetzte Richtung dreht.
 * Geschwindigkeit : Wenn beide gleich sind → fährt der Roboter geradeaus,Wenn unterschiedlich → er dreht.
 * Drehung: Dreheffekt, Wenn rechts > links → der Roboter dreht sich nach links.Umgekehrt → nach rechts.
 * Der Winkel (Richtung des Roboters) wird um die Drehung pro Zeit aktualisiert.
*/
void Roboter::aktualisierePosition(float deltaZeit){
    float effektiveLeistungLinks = motorLinks.getLeistung() * motorLinks.getRichtung();
    float effektiveLeistungRechts = motorRechts.getLeistung() * motorRechts.getRichtung();

    float geschwindigkeit = (effektiveLeistungLinks + effektiveLeistungRechts) / 2.0f;
    float drehung = (effektiveLeistungRechts - effektiveLeistungLinks) * 50.0f;
    //Winkel aktualisiesren
    winkel += drehung * deltaZeit;
    if (winkel >= 360.0f) winkel -= 360.0f;
    if (winkel < 0.0f)    winkel += 360.0f;
    // Bewegung entlang der Aktuellen Richtung
    float rad = winkel * PI / 180.0f;
    x += std::cos(rad) * geschwindigkeit * deltaZeit;
    y += std::sin(rad) * geschwindigkeit * deltaZeit;
    //Neue Position auf Szeneebene
    setPos(x, y);
    //QGraphics-Rotation
    setRotation(winkel);
    //std::cout << "[Roboter] neue Position: (" <<pos().x() << ", " << pos().y() << "), Richtung: " << winkel << "°\n";
}

QPointF Roboter::getCenterPosition() const{
    return scenePos() + rect().center();
}

float Roboter::getX() const{
    return pos().x();
}

float Roboter::getY() const{
    return pos().y();
}

float Roboter::getRichtung() const{
    return winkel;
}


void Roboter::bewegungtesten(){
    Dc_SignalInterpreter Interpreter;
    string Eingabe;
    std::cout << "\n--- [Bewegung test] Steurung mit w/a/s/d | q = Beeden ---\n";
    while(true){
        std::cout << "Eingabe: ";
        std::getline(std::cin, Eingabe);
        if(Eingabe == "q" || Eingabe == "Q"){
            std::cout << "Bewegung Beendet.\n";
            break;
        }
        signaltyp Signal = Interpreter.EingabeInterpretieren(Eingabe);
        bewegungslogik.Empfangeignal(Signal);
        bewegungslogik.Aktualisiereposition(1.0f);
        statusausgeben();
    }
}

void Roboter::statusausgeben(){
    std::cout << "→ Position: (" << bewegungslogik.getx() << ", "
              << bewegungslogik.gety() << "), Richtung: "
              << bewegungslogik.getrichtung() << "°\n";
}
