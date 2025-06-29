#pragma once
#include <QtTest/QtTest>
#include "Wassersensor.h"

/*
Unit Test für Wassersensor Klasse
Getestet:
- Konstruktor und Destruktor
- Wasserquelle setzen
- Starten und Stoppen der Messung
- Letzte Messung abrufen
- Thread-Sicherheit
*/

class TestWassersensor : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void cleanup();
    
    void testKonstruktor();
    void testWasserQuelleSetzen();
    void testStartenUndStoppen();
    void testLetzteMessung();
    void testThreadSicherheit();

private:
    Wassersensor* wassersensor;
}; 