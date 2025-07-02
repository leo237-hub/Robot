#pragma once
#include <string>
#include "Gassensor.h"
#include "TemperaturSensor.h"
#include "Lidarsensor.h"
#include "Kettesensor.h"
#include "GpsSensor.h"
#include "Wassersensor.h"
using namespace std;

/*
Zweck und Verhalten der Sensor-Klasse

Zweck:
Basisklasse für verschiedene Sensortypen im Roboter, verwaltet ID, Typ, Einheit und Messwert.

Verhalten:
Ermöglicht das Messen und Kalibrieren von Sensoren und speichert die letzte Messung.
*/

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