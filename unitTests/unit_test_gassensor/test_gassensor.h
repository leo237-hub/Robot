#pragma once
#include <QtTest/QtTest>
#include "Gassensor.h"

/*
Unit Test für GasSensor Klasse
Getestet:
- Konstruktor und Destruktor
- Gasquelle setzen
- Starten und Stoppen der Messung
- Letzte Messung abrufen
- Grenzwert setzen und abrufen
- Thread-Sicherheit
*/

class TestGassensor : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void cleanup();
    
    void testKonstruktor();
    void testGasQuelleSetzen();
    void testStartenUndStoppen();
    void testLetzteMessung();
    void testGrenzwert();
    void testThreadSicherheit();

private:
    GasSensor* gassensor;
}; 