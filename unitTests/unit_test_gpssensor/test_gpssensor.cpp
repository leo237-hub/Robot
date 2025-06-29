#include "test_gpssensor.h"

void TestGpssensor::init()
{
    gpsSensor = new GPSSensor();
}

void TestGpssensor::cleanup()
{
    delete gpsSensor;
}

/*
Test für Konstruktor
*/
void TestGpssensor::testKonstruktor()
{
    GPSSensor neuerSensor;
    
    /* Initial sollte Position bei (0,0) sein */
    QCOMPARE(neuerSensor.getX(), 0.0);
    QCOMPARE(neuerSensor.getY(), 0.0);
}

/*
Test für Position setzen
*/
void TestGpssensor::testPositionSetzen()
{
    double x = 10.5;
    double y = 20.7;
    
    gpsSensor->setPosition(x, y);
    
    QCOMPARE(gpsSensor->getX(), x);
    QCOMPARE(gpsSensor->getY(), y);
}

/*
Test für X-Koordinaten
*/
void TestGpssensor::testXKoordinaten()
{
    double x = 15.3;
    double y = 25.8;
    
    gpsSensor->setPosition(x, y);
    
    QCOMPARE(gpsSensor->getX(), x);
}

/*
Test für Y-Koordinaten
*/
void TestGpssensor::testYKoordinaten()
{
    double x = 30.1;
    double y = 40.2;
    
    gpsSensor->setPosition(x, y);
    
    QCOMPARE(gpsSensor->getY(), y);
}

/*
Test für Position ändern
*/
void TestGpssensor::testPositionAendern()
{
    /* Erste Position setzen */
    gpsSensor->setPosition(5.0, 10.0);
    QCOMPARE(gpsSensor->getX(), 5.0);
    QCOMPARE(gpsSensor->getY(), 10.0);
    
    /* Position ändern */
    gpsSensor->setPosition(15.0, 25.0);
    QCOMPARE(gpsSensor->getX(), 15.0);
    QCOMPARE(gpsSensor->getY(), 25.0);
}

QTEST_APPLESS_MAIN(TestGpssensor); 