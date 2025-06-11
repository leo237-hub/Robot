#include "test_feuer.h"

void TestFeuer::init()
{
    standardFeuer = new Feuer(0.0, 0.0);
    testFeuer = new Feuer(10.0, 20.0, Qt::red, true, 15.0, 250.0);
    heissesFeuer = new Feuer(5.0, 5.0, Qt::red, false, 30.0, 500.0);
}

void TestFeuer::cleanup()
{
    delete standardFeuer;
    delete testFeuer;
    delete heissesFeuer;
}

/*
Test für Konstruktor mit Standardwerten
*/
void TestFeuer::testKonstruktorMitStandardWerten()
{
    Feuer feuer(10.0, 15.0);
    
    QCOMPARE(feuer.holePosition(), QPointF(10.0, 15.0));
    QCOMPARE(feuer.holeTemperatur(), 100.0f);  // Standard Temperatur
    QCOMPARE(feuer.holeRadius(), 20.0);        // Standard Radius
    QCOMPARE(feuer.istSolid(), false);         // Standard solidStatus
}

/*
Test für Konstruktor mit allen Parametern
*/
void TestFeuer::testKonstruktorMitAllenParametern()
{
    Feuer feuer(25.0, 35.0, Qt::yellow, true, 40.0, 300.0);
    
    QCOMPARE(feuer.holePosition(), QPointF(25.0, 35.0));
    QCOMPARE(feuer.holeTemperatur(), 300.0f);
    QCOMPARE(feuer.holeRadius(), 40.0);
    QCOMPARE(feuer.istSolid(), true);
}

/*
Test mit verschiedenen Temperaturen
*/
void TestFeuer::testKonstruktorMitVerschiedenenTemperaturen()
{
    Feuer kaltesFeuer(0.0, 0.0, Qt::red, false, 20.0, 50.0);
    Feuer mittleresFeuer(0.0, 0.0, Qt::red, false, 20.0, 200.0);
    Feuer extremFeuer(0.0, 0.0, Qt::red, false, 20.0, 1000.0);
    
    QCOMPARE(kaltesFeuer.holeTemperatur(), 50.0f);
    QCOMPARE(mittleresFeuer.holeTemperatur(), 200.0f);
    QCOMPARE(extremFeuer.holeTemperatur(), 1000.0f);
}

/*
Test für Temperatur abfragen
*/
void TestFeuer::testTemperaturAbfragen()
{
    QCOMPARE(standardFeuer->holeTemperatur(), 100.0f);
    QCOMPARE(testFeuer->holeTemperatur(), 250.0f);
    QCOMPARE(heissesFeuer->holeTemperatur(), 500.0f);
}

/*
Test mit verschiedenen Temperaturwerten
*/
void TestFeuer::testTemperaturVerschiedeneWerte()
{
    Feuer sehr_heiss(0.0, 0.0, Qt::red, false, 20.0, 800.0);
    Feuer warm(0.0, 0.0, Qt::red, false, 20.0, 80.0);
    Feuer kuehl(0.0, 0.0, Qt::red, false, 20.0, 25.0);
    
    QVERIFY(sehr_heiss.holeTemperatur() > warm.holeTemperatur());
    QVERIFY(warm.holeTemperatur() > kuehl.holeTemperatur());
    QCOMPARE(sehr_heiss.holeTemperatur(), 800.0f);
    QCOMPARE(warm.holeTemperatur(), 80.0f);
    QCOMPARE(kuehl.holeTemperatur(), 25.0f);
}

/*
Test mit negativen Temperaturwerten
*/
void TestFeuer::testTemperaturNegativeWerte()
{
    Feuer negativFeuer(0.0, 0.0, Qt::red, false, 20.0, -10.0);
    
    QCOMPARE(negativFeuer.holeTemperatur(), -10.0f);
}

/*
Test mit Null Temperatur
*/
void TestFeuer::testTemperaturNullWert()
{
    Feuer nullFeuer(0.0, 0.0, Qt::red, false, 20.0, 0.0);
    
    QCOMPARE(nullFeuer.holeTemperatur(), 0.0f);
}



/*
Test für Standard Feuer Eigenschaften
*/
void TestFeuer::testStandardFeuerEigenschaften()
{
    Feuer standardFeuer(0.0, 0.0);
    
    // Feuer sollte standardmäßig rot sein (wird im Konstruktor gesetzt)
    // Feuer sollte standardmäßig nicht solid sein
    QCOMPARE(standardFeuer.istSolid(), false);
    
    // Standard Radius sollte 20.0 sein
    QCOMPARE(standardFeuer.holeRadius(), 20.0);
    
    // Standard Temperatur sollte 100.0 sein
    QCOMPARE(standardFeuer.holeTemperatur(), 100.0f);
}


