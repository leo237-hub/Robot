#ifndef APPEND_C_GPSSENSOR_H
#define APPEND_C_GPSSENSOR_H
#include <array>
#include <cmath>

class GPSSensor {
private:
    float longitude;
    float latitude;
    float altitude;

public:
    // Constructor
    GPSSensor(float lon, float lat, float alt);

    // Returns current coordinates as an array: [longitude, latitude, altitude]
    std::array<float, 3> koordinatenHolen() const;

    // Calculates 3D distance to another coordinate
    float EntfernungBerechnen(float zielLongitude, float zielLatitude, float zielAltitude) const;
};
#endif //APPEND_C_GPSSENSOR_H
