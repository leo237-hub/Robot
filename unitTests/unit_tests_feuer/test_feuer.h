#pragma once
#include <QtTest/QtTest>
#include "feuer.h"

/*
Unit Test für Feuer Klasse
Getestet:
- Konstruktor mit Standard- und benutzerdefinierten Werten
- Temperatur abfragen und Verhalten
- Korrekte Vererbung von simulationElement
- Standardwerte für Feuer-spezifische Eigenschaften
- Integration mit QGraphics System
*/

class TestFeuer : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void cleanup();
    
    void testKonstruktorMitStandardWerten();
    void testKonstruktorMitAllenParametern();
    void testKonstruktorMitVerschiedenenTemperaturen();
    
    void testTemperaturAbfragen();
    void testTemperaturVerschiedeneWerte();
    void testTemperaturNegativeWerte();
    void testTemperaturNullWert();
    void testStandardFeuerEigenschaften();

private:
    Feuer* standardFeuer;
    Feuer* testFeuer;
    Feuer* heissesFeuer;
};