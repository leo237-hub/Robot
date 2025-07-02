#pragma once
#include<string.h>
#include<iostream>
#include"Sensors.h"
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
    string TemperaturSensor,
           FeutigkeitSensor,
           Lidarsensor,
           GPSsensor,
           Gassensor,
           DCmotor;

public:
    Selfcheck();
    ~Selfcheck();
    std::vector<Sensor * > Sensor;
    string TemperaturSensPruefen();
    string FeuchtigkeitSensPruefen();
    string LidarSensorPruefen();
    string WasserSensPruefen();
    string GPsSensorPruefen();
    string DCMotorPruefen();
    string KetteSensPruefen();
};