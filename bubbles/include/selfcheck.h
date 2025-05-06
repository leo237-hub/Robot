#ifndef SELFCHECK_H
#define SELFCHECK_H
//create by Leonel on 24.04.2025

#include<string.h>
#include<iostream>



using namespace  std;

class Selfcheck
{
private:
    string TemperaturSensor,
           FeutigkeitSensor,
                Lidarsensor,
                  GPSsensor,
                  Gassensor,
                    DCmotor;
public:
    string TemperaturSensPruefen();
    string FeuchtigkeitSensPruefen();
    string LidarSensorPruefen();
    string WasserSensPruefen();
    string GPsSensorPruefen();
    string DCMotorPruefen();
    string KetteSensPruefen();

    Selfcheck(); //Konstruktor
    ~Selfcheck(); //Destruktor
};

#endif // SELFCHECK_H
