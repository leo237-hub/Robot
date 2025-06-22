#pragma once
#include <QtTest/QtTest>
#include "simulationElement.h"

/*
Unit Test für SimulationElement Klasse
Getestet:
- Konstruktor mit verschiedenen Parametern
- Solid Status setzen und abfragen
- Radius Funktionalität
- Korrekte Vererbung von Position
- Verschiedene Farben und Eigenschaften
*/

class TestSimulationElement : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void cleanup();
    
    void testKonstruktorMitStandardWerten();
    void testKonstruktorMitAllenParametern();
    void testKonstruktorMitVerschiedenenFarben();
    
    void testSolidStatusSetzenUndAbfragen();
    void testSolidStatusAendern();
    
    void testRadiusAbfragen();
    void testRadiusVerschiedeneWerte();

private:
    simulationElement* standardElement;
    simulationElement* testElement;
};