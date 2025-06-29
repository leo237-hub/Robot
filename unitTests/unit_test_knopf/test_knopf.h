#pragma once
#include <QtTest/QtTest>
#include "knopf.h"

/*
Unit Test für Knopf Klasse
Getestet:
- Konstruktor mit Standard- und benutzerdefinierten Werten
- Status setzen und abfragen
- ID abfragen
*/

class TestKnopf : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void cleanup();
    
    void testKonstruktorStandard();
    void testKonstruktorMitParametern();
    void testStatusSetzen();
    void testStatusAbfragen();
    void testIDAbfragen();

private:
    Knopf* knopf;
}; 