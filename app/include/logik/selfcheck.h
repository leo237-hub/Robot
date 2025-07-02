#pragma once
#include<string.h>
#include<iostream>
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
    TemperaturSensor* tempSensor[3];
    LidarSensor* lidarSensor[3];
    GPSSensor* gpsSensor[3];
    GasSensor* gasSensor[3];
    Wassersensor* wasserSensor[3];
    Kettensensor* ketteSensor[3];

    const float maxAbweichung = 2.0f;

public:
    Selfcheck(TemperaturSensor* t[3], LidarSensor* l[3], GPSSensor* g[3], GasSensor* gas[3], Wassersensor* w[3], Kettensensor* k[3]);
    ~Selfcheck();
    string TemperaturSensPruefen();
    string LidarSensorPruefen();
    string WasserSensPruefen();
    string GPsSensorPruefen();
    string GassensorPruefen();
    string KetteSensPruefen();
};
