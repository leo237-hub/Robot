#pragma once

using namespace  std;
#include <vector>
#include "GpsSensor.h"

/*
Zweck und Verhalten der LidarSensor-Klasse

Zweck:
Ermöglicht die Erkennung von Hindernissen und die Abstandsmessung mittels Lidar-Technologie.

Verhalten:
Misst Distanzen zu Hindernissen, aktualisiert die Messwerte und stellt sie zur Verfügung.
*/

struct Obstacle {
    double x;
    double y;
    double radius;
};

class LidarSensor {
public:
    LidarSensor(GPSSensor* gpsSensor, double maxRange, int numBeams);
    void update(const std::vector<Obstacle>& obstacles);
    const std::vector<double>& getDistances() const;
    bool istHindernisVorne(double sicherheitsAbstand, double winkelStart = -30.0, double winkelEnde = 30.0) const;

private:
    double measureBeam(int beamIndex, const std::vector<Obstacle>& obstacles);
    GPSSensor* gps;
    double maxRange;
    int numBeams;
    vector<double> distances;
};

