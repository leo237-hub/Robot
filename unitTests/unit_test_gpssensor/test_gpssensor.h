#pragma once
#include <QtTest/QtTest>
#include "GpsSensor.h"

/*
Unit Test für GPSSensor Klasse
Getestet:
- Konstruktor
- Position setzen und abrufen
- X und Y Koordinaten
*/

class TestGpssensor : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void cleanup();
    
    void testKonstruktor();
    void testPositionSetzen();
    void testXKoordinaten();
    void testYKoordinaten();
    void testPositionAendern();

private:
    GPSSensor* gpsSensor;
}; 