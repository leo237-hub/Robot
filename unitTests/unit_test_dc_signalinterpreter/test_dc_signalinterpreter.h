#pragma once
#include <QtTest/QtTest>
#include "Dc-SignalInterpreter.h"

/*
Unit Test für Dc_SignalInterpreter Klasse
Getestet:
- Eingabe Interpretation für verschiedene Bewegungsrichtungen
- Groß- und Kleinschreibung
- Ungültige Eingaben
- Korrekte Rückgabe von signaltyp Enum
*/

class TestDcSignalInterpreter : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void cleanup();
    
    void testEingabeVorwaerts();
    void testEingabeRueckwaerts();
    void testEingabeLinks();
    void testEingabeRechts();
    
    void testEingabeGrossschreibung();
    void testEingabeKleinschreibung();
    
    void testUngueltigeEingabe();
    void testLeereEingabe();
    void testMehrereZeichen();

private:
    Dc_SignalInterpreter* interpreter;
};