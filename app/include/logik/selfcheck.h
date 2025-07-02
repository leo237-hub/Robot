#pragma once
#include<string.h>
#include<iostream>
#include"Sensors.h"
#include "TemperaturSensor.h"
#include "Lidarsensor.h"
#include "GpsSensor.h"
#include "Gassensor.h"
#include "Wassersensor.h"
#include "Kettesensor.h"
using namespace  std;

/*
Zweck und Verhalten der Selfcheck-Klasse

Zweck:
Führt Selbsttests für verschiedene Sensoren und Aktoren des Roboters durch.

Verhalten:
Prüft die Funktionsfähigkeit der wichtigsten Komponenten und gibt Prüfergebnisse als Strings zurück.
*/

class Selfcheck {
private:
    // 3 istanze per ogni sensore
    TemperaturSensor* tempSensor[3];
    LidarSensor* lidarSensor[3];
    GPSSensor* gpsSensor[3];
    GasSensor* gasSensor[3];
    Wassersensor* wasserSensor[3];
    Kettensensor* ketteSensor[3];

    // Soglia massima di differenza accettata
    const float maxAbweichung = 2.0f; // esempio per sensori float

public:
    Selfcheck(TemperaturSensor* t[3], LidarSensor* l[3], GPSSensor* g[3], GasSensor* gas[3], Wassersensor* w[3], Kettensensor* k[3]);
    ~Selfcheck();
    std::vector<Sensor * > Sensor;
    string TemperaturSensPruefen();
    string LidarSensorPruefen();
    string WasserSensPruefen();
    string GPsSensorPruefen();
    string GassensorPruefen();
    string KetteSensPruefen();
};