#ifndef APPEND_C_SENSORS_H
#define APPEND_C_SENSORS_H
#include <string>

// Include other sensor headers
#include "Gassensor.h"
#include "TemperaturSensor.h"
#include "Feuchtigkeitssensor.h"
#include "Lidarsensor.h"
#include "Kettesensor.h"
#include "GpsSensor.h"
#include "Wassersensor.h"

class Sensor {
private:
    std::string sensorID;
    std::string type;
    float letzteMessung;
    std::string Einheit;

public:
    // Constructor
    Sensor(const std::string& id, const std::string& typ, const std::string& einheit);

    // Simulate or perform a measurement
    float messen();

    // Simulate calibration
    void kalibrieren();
};
#endif //APPEND_C_SENSORS_H
