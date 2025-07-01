// LidarSensor.cpp
#include "GpsSensor.h"
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
LidarSensor::LidarSensor(GPSSensor* gpsSensor, double maxRange, int numBeams)
    : gps(gpsSensor), maxRange(maxRange), numBeams(numBeams), distances(numBeams, maxRange)
{
   srand(static_cast<unsigned int>(std::time(nullptr)));
}

void LidarSensor::update(const std::vector<Obstacle>& obstacles) {
    for (int i = 0; i < numBeams; ++i) {
        distances[i] = measureBeam(i, obstacles);
    }
}

const std::vector<double>& LidarSensor::getDistances() const {
    return distances;
}


double LidarSensor::measureBeam(int beamIndex, const std::vector<Obstacle>& obstacles) {
    double angle = (2.0 * M_PI * beamIndex) / numBeams;

    double sensorX = gps->getX();
    double sensorY = gps->getY();

    double closestDist = maxRange;

    for (const auto& obs : obstacles) {
        double dx = obs.x - sensorX;
        double dy = obs.y - sensorY;

        // Projektion des Vektors auf Strahlrichtung
        double proj = dx * std::cos(angle) + dy * std::sin(angle);

        if (proj < 0 || proj > maxRange)
            continue;

        // Abstand des Objekts vom Strahl (senkrecht)
        double perpDist = std::abs(-dx * std::sin(angle) + dy * std::cos(angle));

        if (perpDist <= obs.radius) {
            double offset = std::sqrt(obs.radius * obs.radius - perpDist * perpDist);
            double distToObstacle = proj - offset;
            if (distToObstacle >= 0 && distToObstacle < closestDist) {
                closestDist = distToObstacle;
            }
        }
    }

    return closestDist;
}

