#pragma once
#include <QtTest/QtTest>
#include "lampe.h"

/*
Unit Test für Lampe Klasse
Getestet:
- Konstruktor und Destruktor
- Einschalten und Ausschalten
- Status abfragen
- Vererbung von Aktoren
*/

class TestLampe : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void cleanup();
    
    void testKonstruktor();
    void testEinschalten();
    void testAusschalten();
    void testStatusAbfragen();
    void testMehrfachSchalten();

private:
    Lampe* lampe;
}; 