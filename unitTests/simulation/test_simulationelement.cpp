#include "test_simulationelement.h"

void TestSimulationElement::init()
{
    standardElement = new simulationElement(0.0, 0.0, Qt::blue, false);
    testElement = new simulationElement(10.0, 20.0, Qt::red, true, 25.0);
}

void TestSimulationElement::cleanup()
{
    delete standardElement;
    delete testElement;
}

/*
Test für Konstruktor mit Standardwerten
*/
void TestSimulationElement::testKonstruktorMitStandardWerten()
{
    simulationElement element(5.0, 10.0, Qt::green, false);
    
    QCOMPARE(element.holePosition(), QPointF(5.0, 10.0));
    QCOMPARE(element.istSolid(), false);
    QCOMPARE(element.holeRadius(), 20.0);  // Standard radius
}

/*
Test für Konstruktor mit allen Parametern
*/
void TestSimulationElement::testKonstruktorMitAllenParametern()
{
    simulationElement element(15.0, 25.0, Qt::yellow, true, 30.0);
    
    QCOMPARE(element.holePosition(), QPointF(15.0, 25.0));
    QCOMPARE(element.istSolid(), true);
    QCOMPARE(element.holeRadius(), 30.0);
}

/*
Test mit verschiedenen Farben
*/
void TestSimulationElement::testKonstruktorMitVerschiedenenFarben()
{
    simulationElement rotesElement(0.0, 0.0, Qt::red, false);
    simulationElement blauesElement(0.0, 0.0, Qt::blue, false);
    simulationElement gruesesElement(0.0, 0.0, Qt::green, false);
    
    // Alle sollten korrekt erstellt werden
    QVERIFY(rotesElement.holeRadius() > 0);
    QVERIFY(blauesElement.holeRadius() > 0);
    QVERIFY(gruesesElement.holeRadius() > 0);
}

/*
Test für Solid Status abfragen
*/
void TestSimulationElement::testSolidStatusSetzenUndAbfragen()
{
    QCOMPARE(standardElement->istSolid(), false);
    QCOMPARE(testElement->istSolid(), true);
}

/*
Test für Änderung des Solid Status
*/
void TestSimulationElement::testSolidStatusAendern()
{
    standardElement->setSolid(true);
    QCOMPARE(standardElement->istSolid(), true);
    
    standardElement->setSolid(false);
    QCOMPARE(standardElement->istSolid(), false);
    
    testElement->setSolid(false);
    QCOMPARE(testElement->istSolid(), false);
}

/*
Test für Radius abfragen
*/
void TestSimulationElement::testRadiusAbfragen()
{
    QCOMPARE(standardElement->holeRadius(), 20.0);
    QCOMPARE(testElement->holeRadius(), 25.0);
}

/*
Test mit verschiedenen Radius Werten
*/
void TestSimulationElement::testRadiusVerschiedeneWerte()
{
    simulationElement kleinesElement(0.0, 0.0, Qt::black, false, 5.0);
    simulationElement grossesElement(0.0, 0.0, Qt::white, false, 100.0);
    
    QCOMPARE(kleinesElement.holeRadius(), 5.0);
    QCOMPARE(grossesElement.holeRadius(), 100.0);
}



