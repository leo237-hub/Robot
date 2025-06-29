#pragma once
#include <string>
#include "Gassensor.h"
#include "TemperaturSensor.h"
#include "Feuchtigkeitssensor.h"
#include "Lidarsensor.h"
#include "Kettesensor.h"
#include "GpsSensor.h"
#include "Wassersensor.h"
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