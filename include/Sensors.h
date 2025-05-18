#pragma once
#include <string>

#include "sensor/Gassensor.h"
#include "sensor/TemperaturSensor.h"
#include "sensor/Feuchtigkeitssensor.h"
#include "sensor/Lidarsensor.h"
#include "sensor/Kettesensor.h"
#include "sensor/GpsSensor.h"
#include "sensor/Wassersensor.h"


using namespace std;
class Sensor {
private:
    std::string sensorID;
    std::string type;
    float letzteMessung;
    std::string Einheit;

public:
    Sensor(const std::string& id, const std::string& typ, const std::string& einheit);
    float messen();
    void kalibrieren();
};

