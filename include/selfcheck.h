#ifndef SELFCHECK_H
#define SELFCHECK_H
#include<string.h>
#include<iostream>
#include"sensors.h"
using namespace  std;
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
#endif // SELFCHECK_H
