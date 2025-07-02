#pragma once

using namespace  std;
#include <vector>

/*
Zweck und Verhalten der LidarSensor-Klasse

Zweck:
Ermöglicht die Erkennung von Hindernissen und die Abstandsmessung mittels Lidar-Technologie.

Verhalten:
Misst Distanzen zu Hindernissen, aktualisiert die Messwerte und stellt sie zur Verfügung.
*/

// Struktur für Hindernisse (Obstacle)
struct Obstacle {
    double x;
    double y;
    double radius;
};

class LidarSensor {
public:
    LidarSensor(double maxReichweite, int anzahlStrahlen);
    void setzePosition(double x, double y); // Setzt die aktuelle Sensorposition
    void update(const std::vector<Obstacle>& hindernisse);
    const std::vector<double>& gibDistanzen() const;
    bool istHindernisVorne(double sicherheitsAbstand, double winkelStart = -30.0, double winkelEnde = 30.0) const;

private:
    double maxReichweite;
    int anzahlStrahlen;
    std::vector<double> distanzen;
    double sensorX = 0.0;
    double sensorY = 0.0;
    double messeStrahl(int strahlIndex, const std::vector<Obstacle>& hindernisse);
};

