#pragma once

using namespace  std;
#include <vector>
#include "GpsSensor.h"

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

private:
    double measureBeam(int beamIndex, const std::vector<Obstacle>& obstacles);
    GPSSensor* gps;
    double maxRange;
    int numBeams;
    vector<double> distances;
};

