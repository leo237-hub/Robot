#include "BewegungsSimulation.h"
#include "BewegungsRoboter.h"
#include <cmath>
#define PI 3.14159265f

BewegungsSimulation::BewegungsSimulation(BewegungsRoboter* robot)
    : roboter(robot), x(0.0f), y(0.0f), winkel(0.0f) {
}

void BewegungsSimulation::aktualisierePosition(float deltazeit) {
    // Lese Motorzustand vom Roboter
    float effektiveLeistungRechts = roboter->getMotorRechtsLeistung() * roboter->getMotorRechtsRichtung();
    float effektiveLeistungLinks = roboter->getMotorLinksLeistung() * roboter->getMotorLinksRichtung();
    
    // Berechne Geschwindigkeit und Drehung
    float geschwindigkeit = (effektiveLeistungLinks + effektiveLeistungRechts) / 2.0f;
    float drehung = (effektiveLeistungRechts - effektiveLeistungLinks) * 30.0f;
    
    // Geschwindigkeitsmultiplikator für kontrolliertere Bewegung
    geschwindigkeit *= GESCHWINDIGKEITS_MULTIPLIKATOR;
    
    // Winkel aktualisieren
    winkel += drehung * deltazeit;
    if (winkel >= 360.0f) winkel -= 360.0f;
    if (winkel < 0.0f) winkel += 360.0f;
    
    // Bewegung entlang der aktuellen Richtung
    float rad = winkel * PI / 180.0f;
    x += std::cos(rad) * geschwindigkeit * deltazeit;
    y += std::sin(rad) * geschwindigkeit * deltazeit;
}

float BewegungsSimulation::getX() const {
    return x;
}

float BewegungsSimulation::getY() const {
    return y;
}

float BewegungsSimulation::getWinkel() const {
    return winkel;
}

void BewegungsSimulation::setzePosition(float x, float y, float winkel) {
    this->x = x;
    this->y = y;
    this->winkel = winkel;
} 