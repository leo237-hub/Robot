#pragma once
#include <array>
#include <cmath>

class GPSSensor {
private:
    float longitude;
    float latitude;
    float altitude;

public:
    GPSSensor(float lon, float lat, float alt);
    std::array<float, 3> koordinatenHolen() const;
    float EntfernungBerechnen(float zielLongitude, float zielLatitude, float zielAltitude) const;
};

