#include "test_wassersensor.h"

void TestWassersensor::init()
{
    wassersensor = new Wassersensor();
}

void TestWassersensor::cleanup()
{
    delete wassersensor;
}

/*
Test für Konstruktor
*/
void TestWassersensor::testKonstruktor()
{
    Wassersensor sensor;
    
    /* Initial sollte keine Messung vorhanden sein */
    QCOMPARE(sensor.getLetzteMessung(), 0.0f);
}

/*
Test für Wasserquelle setzen
*/
void TestWassersensor::testWasserQuelleSetzen()
{
    float testWert = 42.5f;
    auto quelle = [testWert]() -> float { return testWert; };
    
    wassersensor->setWasserQuelle(quelle);
    wassersensor->starten();
    
    /* Kurz warten für Messung */
    QThread::msleep(100);
    
    QCOMPARE(wassersensor->getLetzteMessung(), testWert);
}

/*
Test für Starten und Stoppen
*/
void TestWassersensor::testStartenUndStoppen()
{
    float testWert = 15.0f;
    auto quelle = [testWert]() -> float { return testWert; };
    
    wassersensor->setWasserQuelle(quelle);
    wassersensor->starten();
    
    /* Kurz warten */
    QThread::msleep(50);
    
    wassersensor->stoppen();
    
    /* Messung sollte weiterhin verfügbar sein */
    QCOMPARE(wassersensor->getLetzteMessung(), testWert);
}

/*
Test für letzte Messung
*/
void TestWassersensor::testLetzteMessung()
{
    float testWert = 25.0f;
    auto quelle = [testWert]() -> float { return testWert; };
    
    wassersensor->setWasserQuelle(quelle);
    wassersensor->starten();
    
    /* Kurz warten für Messung */
    QThread::msleep(100);
    
    float messung = wassersensor->getLetzteMessung();
    QCOMPARE(messung, testWert);
}

/*
Test für Thread-Sicherheit
*/
void TestWassersensor::testThreadSicherheit()
{
    float testWert = 30.0f;
    auto quelle = [testWert]() -> float { return testWert; };
    
    wassersensor->setWasserQuelle(quelle);
    wassersensor->starten();
    
    /* Mehrfach Zugriff auf letzte Messung */
    for (int i = 0; i < 10; ++i) {
        float messung = wassersensor->getLetzteMessung();
        QCOMPARE(messung, testWert);
    }
    
    wassersensor->stoppen();
}

QTEST_APPLESS_MAIN(TestWassersensor); 