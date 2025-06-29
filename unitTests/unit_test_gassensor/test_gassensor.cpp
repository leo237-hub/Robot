#include "test_gassensor.h"

void TestGassensor::init()
{
    gassensor = new GasSensor();
}

void TestGassensor::cleanup()
{
    delete gassensor;
}

/*
Test für Konstruktor
*/
void TestGassensor::testKonstruktor()
{
    GasSensor sensor;
    
    /* Initial sollte keine Messung vorhanden sein */
    QCOMPARE(sensor.getLetzteMessung(), 0.0f);
    QCOMPARE(sensor.getGrenzwert(), 0.0f);
}

/*
Test für Gasquelle setzen
*/
void TestGassensor::testGasQuelleSetzen()
{
    float testWert = 35.7f;
    auto quelle = [testWert]() -> float { return testWert; };
    
    gassensor->setGasQuelle(quelle);
    gassensor->starten();
    
    /* Kurz warten für Messung */
    QThread::msleep(100);
    
    QCOMPARE(gassensor->getLetzteMessung(), testWert);
}

/*
Test für Starten und Stoppen
*/
void TestGassensor::testStartenUndStoppen()
{
    float testWert = 20.0f;
    auto quelle = [testWert]() -> float { return testWert; };
    
    gassensor->setGasQuelle(quelle);
    gassensor->starten();
    
    /* Kurz warten */
    QThread::msleep(50);
    
    gassensor->stoppen();
    
    /* Messung sollte weiterhin verfügbar sein */
    QCOMPARE(gassensor->getLetzteMessung(), testWert);
}

/*
Test für letzte Messung
*/
void TestGassensor::testLetzteMessung()
{
    float testWert = 45.0f;
    auto quelle = [testWert]() -> float { return testWert; };
    
    gassensor->setGasQuelle(quelle);
    gassensor->starten();
    
    /* Kurz warten für Messung */
    QThread::msleep(100);
    
    float messung = gassensor->getLetzteMessung();
    QCOMPARE(messung, testWert);
}

/*
Test für Grenzwert
*/
void TestGassensor::testGrenzwert()
{
    float grenzwert = 50.0f;
    gassensor->setzeGrenzwert(grenzwert);
    
    QCOMPARE(gassensor->getGrenzwert(), grenzwert);
    
    /* Grenzwert ändern */
    float neuerGrenzwert = 75.0f;
    gassensor->setzeGrenzwert(neuerGrenzwert);
    
    QCOMPARE(gassensor->getGrenzwert(), neuerGrenzwert);
}

/*
Test für Thread-Sicherheit
*/
void TestGassensor::testThreadSicherheit()
{
    float testWert = 60.0f;
    auto quelle = [testWert]() -> float { return testWert; };
    
    gassensor->setGasQuelle(quelle);
    gassensor->starten();
    
    /* Mehrfach Zugriff auf letzte Messung */
    for (int i = 0; i < 10; ++i) {
        float messung = gassensor->getLetzteMessung();
        QCOMPARE(messung, testWert);
    }
    
    gassensor->stoppen();
}

QTEST_APPLESS_MAIN(TestGassensor); 