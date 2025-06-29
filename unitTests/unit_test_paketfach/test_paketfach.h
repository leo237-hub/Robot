#pragma once
#include <QtTest/QtTest>
#include "paketfach.h"

/*
Unit Test für PaketFach Klasse
Getestet:
- Konstruktor und Destruktor
- Öffnen und Schließen
- Zustand abfragen
*/

class TestPaketfach : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void cleanup();
    
    void testKonstruktor();
    void testOeffnen();
    void testSchliessen();
    void testZustandAbfragen();
    void testMehrfachOeffnenSchliessen();

private:
    PaketFach* paketfach;
}; 