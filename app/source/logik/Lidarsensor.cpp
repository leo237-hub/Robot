// LidarSensor.cpp
#include "Lidarsensor.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

/*
-Simuliert einen Lidar-Sensor, der aus mehreren Strahlen (Beams) rundum Entfernungen misst.
-Nimmt einen GPS-Sensor, maximale Reichweite (maxRange) und Anzahl der Strahlen (numBeams) als Parameter.
-Initialisiert ein Distanz-Array mit numBeams Einträgen, alle auf maxRange gesetzt
-update: Für jeden Strahl (beamIndex) wird measureBeam aufgerufen, um die Entfernung zum nächstgelegenen Hindernis in dieser Richtung zu messen.
*/
LidarSensor::LidarSensor(double maxReichweite, int anzahlStrahlen)
    : maxReichweite(maxReichweite), anzahlStrahlen(anzahlStrahlen), distanzen(anzahlStrahlen, maxReichweite), sensorX(0.0), sensorY(0.0)
{
    srand(static_cast<unsigned int>(std::time(nullptr)));
}

void LidarSensor::setzePosition(double x, double y) {
    sensorX = x;
    sensorY = y;
}

void LidarSensor::update(const std::vector<Obstacle>& hindernisse) {
    for (int i = 0; i < anzahlStrahlen; ++i) {
        distanzen[i] = messeStrahl(i, hindernisse);
    }
}

const std::vector<double>& LidarSensor::gibDistanzen() const {
    return distanzen;
}

double LidarSensor::messeStrahl(int strahlIndex, const std::vector<Obstacle>& hindernisse) {
    double winkel = (2.0 * M_PI * strahlIndex) / anzahlStrahlen;
    double naechsteDistanz = maxReichweite;
    for (const auto& hindernis : hindernisse) {
        double dx = hindernis.x - sensorX;
        double dy = hindernis.y - sensorY;
        double projektion = dx * std::cos(winkel) + dy * std::sin(winkel);
        if (projektion < 0 || projektion > maxReichweite)
            continue;
        double senkrechterAbstand = std::abs(-dx * std::sin(winkel) + dy * std::cos(winkel));
        if (senkrechterAbstand <= hindernis.radius) {
            double offset = std::sqrt(hindernis.radius * hindernis.radius - senkrechterAbstand * senkrechterAbstand);
            double distZumHindernis = projektion - offset;
            if (distZumHindernis >= 0 && distZumHindernis < naechsteDistanz) {
                naechsteDistanz = distZumHindernis;
            }
        }
    }
    return naechsteDistanz;
}

bool LidarSensor::istHindernisVorne(double sicherheitsAbstand, double winkelStart, double winkelEnde) const {
    int startIdx = static_cast<int>((winkelStart + 360.0) / 360.0 * anzahlStrahlen) % anzahlStrahlen;
    int endIdx = static_cast<int>((winkelEnde + 360.0) / 360.0 * anzahlStrahlen) % anzahlStrahlen;
    if (startIdx > endIdx) endIdx += anzahlStrahlen;
    for (int i = startIdx; i <= endIdx; ++i) {
        int idx = i % anzahlStrahlen;
        if (distanzen[idx] < sicherheitsAbstand) {
            return true;
        }
    }
    return false;
}

