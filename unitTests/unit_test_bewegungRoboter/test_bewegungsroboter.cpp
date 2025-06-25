#include "test_bewegungsroboter.h"

void TestBewegungsRoboter::init()
{
    roboter = new BewegungsRoboter();
    roboterMitStart = new BewegungsRoboter(10.0f, 20.0f, 45.0f);
}

void TestBewegungsRoboter::cleanup()
{
    delete roboter;
    delete roboterMitStart;
}

/*
Test für Konstruktor mit Standardwerten
*/
void TestBewegungsRoboter::testKonstruktorStandardwerte()
{
    BewegungsRoboter testRoboter;
    
    QCOMPARE(testRoboter.getx(), 0.0f);
    QCOMPARE(testRoboter.gety(), 0.0f);
    QCOMPARE(testRoboter.getrichtung(), 0.0f);
}

/*
Test für Konstruktor mit Parametern
*/
void TestBewegungsRoboter::testKonstruktorMitParametern()
{
    BewegungsRoboter testRoboter(15.5f, 25.3f, 90.0f);
    
    QCOMPARE(testRoboter.getx(), 15.5f);
    QCOMPARE(testRoboter.gety(), 25.3f);
    QCOMPARE(testRoboter.getrichtung(), 90.0f);
}

/*
Test für Empfang Signal Vorwärts
*/
void TestBewegungsRoboter::testEmpfangeSignalVorwaerts()
{
    // Test sollte ohne Fehler ausgeführt werden
    roboter->Empfangesignal(signaltyp::Vorvaerts);
    QVERIFY(true);
}

/*
Test für Empfang Signal Rückwärts
*/
void TestBewegungsRoboter::testEmpfangeSignalRueckwaerts()
{
    // Test sollte ohne Fehler ausgeführt werden
    roboter->Empfangesignal(signaltyp::Rueckwaerts);
    QVERIFY(true);
}

/*
Test für Empfang Signal Links
*/
void TestBewegungsRoboter::testEmpfangeSignalLinks()
{
    // Test sollte ohne Fehler ausgeführt werden
    roboter->Empfangesignal(signaltyp::Links);
    QVERIFY(true);
}

/*
Test für Empfang Signal Rechts
*/
void TestBewegungsRoboter::testEmpfangeSignalRechts()
{
    // Test sollte ohne Fehler ausgeführt werden
    roboter->Empfangesignal(signaltyp::Rechts);
    QVERIFY(true);
}

/*
Test für Empfang Signal Keine
*/
void TestBewegungsRoboter::testEmpfangeSignalKeine()
{
    // Test sollte ohne Fehler ausgeführt werden
    roboter->Empfangesignal(signaltyp::keine);
    QVERIFY(true);
}

/*
Test für Position abfragen
*/
void TestBewegungsRoboter::testPositionAbfragen()
{
    QCOMPARE(roboter->getx(), 0.0f);
    QCOMPARE(roboter->gety(), 0.0f);
    
    QCOMPARE(roboterMitStart->getx(), 10.0f);
    QCOMPARE(roboterMitStart->gety(), 20.0f);
}

/*
Test für Richtung abfragen
*/
void TestBewegungsRoboter::testRichtungAbfragen()
{
    QCOMPARE(roboter->getrichtung(), 0.0f);
    QCOMPARE(roboterMitStart->getrichtung(), 45.0f);
}


/*
Test für mehrere Signale hintereinander
*/
void TestBewegungsRoboter::testMehrereSignaleHintereinander()
{
    // Teste verschiedene Signale hintereinander
    roboter->Empfangesignal(signaltyp::Vorvaerts);
    roboter->Empfangesignal(signaltyp::Links);
    roboter->Empfangesignal(signaltyp::Rueckwaerts);
    roboter->Empfangesignal(signaltyp::Rechts);
    roboter->Empfangesignal(signaltyp::keine);
    
    // Alle Signale sollten ohne Fehler verarbeitet werden
    QVERIFY(true);
}

QTEST_APPLESS_MAIN(TestBewegungsRoboter);
