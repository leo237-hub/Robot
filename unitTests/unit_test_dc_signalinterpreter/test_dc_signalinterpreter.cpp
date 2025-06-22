#include "test_dc_signalinterpreter.h"

void TestDcSignalInterpreter::init()
{
    interpreter = new Dc_SignalInterpreter();
}

void TestDcSignalInterpreter::cleanup()
{
    delete interpreter;
}

/*
Test für Vorwärts Bewegung
*/
void TestDcSignalInterpreter::testEingabeVorwaerts()
{
    QCOMPARE(interpreter->EingabeInterpretieren("w"), signaltyp::Vorvaerts);
    QCOMPARE(interpreter->EingabeInterpretieren("W"), signaltyp::Vorvaerts);
}

/*
Test für Rückwärts Bewegung
*/
void TestDcSignalInterpreter::testEingabeRueckwaerts()
{
    QCOMPARE(interpreter->EingabeInterpretieren("s"), signaltyp::Rueckwaerts);
    QCOMPARE(interpreter->EingabeInterpretieren("S"), signaltyp::Rueckwaerts);
}

/*
Test für Links Bewegung
*/
void TestDcSignalInterpreter::testEingabeLinks()
{
    QCOMPARE(interpreter->EingabeInterpretieren("a"), signaltyp::Links);
    QCOMPARE(interpreter->EingabeInterpretieren("A"), signaltyp::Links);
}

/*
Test für Rechts Bewegung
*/
void TestDcSignalInterpreter::testEingabeRechts()
{
    QCOMPARE(interpreter->EingabeInterpretieren("d"), signaltyp::Rechts);
    QCOMPARE(interpreter->EingabeInterpretieren("D"), signaltyp::Rechts);
}

/*
Test für alle Großbuchstaben
*/
void TestDcSignalInterpreter::testEingabeGrossschreibung()
{
    QCOMPARE(interpreter->EingabeInterpretieren("W"), signaltyp::Vorvaerts);
    QCOMPARE(interpreter->EingabeInterpretieren("S"), signaltyp::Rueckwaerts);
    QCOMPARE(interpreter->EingabeInterpretieren("A"), signaltyp::Links);
    QCOMPARE(interpreter->EingabeInterpretieren("D"), signaltyp::Rechts);
}

/*
Test für alle Kleinbuchstaben
*/
void TestDcSignalInterpreter::testEingabeKleinschreibung()
{
    QCOMPARE(interpreter->EingabeInterpretieren("w"), signaltyp::Vorvaerts);
    QCOMPARE(interpreter->EingabeInterpretieren("s"), signaltyp::Rueckwaerts);
    QCOMPARE(interpreter->EingabeInterpretieren("a"), signaltyp::Links);
    QCOMPARE(interpreter->EingabeInterpretieren("d"), signaltyp::Rechts);
}

/*
Test für ungültige Eingaben
*/
void TestDcSignalInterpreter::testUngueltigeEingabe()
{
    QCOMPARE(interpreter->EingabeInterpretieren("x"), signaltyp::keine);
    QCOMPARE(interpreter->EingabeInterpretieren("z"), signaltyp::keine);
    QCOMPARE(interpreter->EingabeInterpretieren("1"), signaltyp::keine);
    QCOMPARE(interpreter->EingabeInterpretieren("!"), signaltyp::keine);
}

/*
Test für leere Eingabe
*/
void TestDcSignalInterpreter::testLeereEingabe()
{
    QCOMPARE(interpreter->EingabeInterpretieren(""), signaltyp::keine);
}

/*
Test für mehrere Zeichen
*/
void TestDcSignalInterpreter::testMehrereZeichen()
{
    QCOMPARE(interpreter->EingabeInterpretieren("wa"), signaltyp::keine);
    QCOMPARE(interpreter->EingabeInterpretieren("ws"), signaltyp::keine);
    QCOMPARE(interpreter->EingabeInterpretieren("wasd"), signaltyp::keine);
}

QTEST_APPLESS_MAIN(TestDcSignalInterpreter);