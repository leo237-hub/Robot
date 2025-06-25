#pragma once
#include <QtTest/QtTest>
#include "BewegungsRoboter.h"

/*
Unit Test für BewegungsRoboter Klasse
Getestet:
- Konstruktor mit verschiedenen Startwerten
- Signal Empfang und Verarbeitung
- Position und Richtung abfragen
- Verschiedene Bewegungskommandos
- Start Funktionalität
*/

class TestBewegungsRoboter : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void cleanup();
    
    void testKonstruktorStandardwerte();
    void testKonstruktorMitParametern();
    
    void testEmpfangeSignalVorwaerts();
    void testEmpfangeSignalRueckwaerts();
    void testEmpfangeSignalLinks();
    void testEmpfangeSignalRechts();
    void testEmpfangeSignalKeine();
    
    void testPositionAbfragen();
    void testRichtungAbfragen();
    
    void testMehrereSignaleHintereinander();

private:
    BewegungsRoboter* roboter;
    BewegungsRoboter* roboterMitStart;
};
