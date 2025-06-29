#include "test_lampe.h"

void TestLampe::init()
{
    lampe = new Lampe();
}

void TestLampe::cleanup()
{
    delete lampe;
}

/*
Test für Konstruktor
*/
void TestLampe::testKonstruktor()
{
    Lampe neueLampe;
    
    /* Lampe sollte initial ausgeschaltet sein */
    QCOMPARE(neueLampe.istEingeschaltet(), false);
}

/*
Test für Einschalten
*/
void TestLampe::testEinschalten()
{
    lampe->einschalten();
    
    QCOMPARE(lampe->istEingeschaltet(), true);
}

/*
Test für Ausschalten
*/
void TestLampe::testAusschalten()
{
    /* Erst einschalten */
    lampe->einschalten();
    QCOMPARE(lampe->istEingeschaltet(), true);
    
    /* Dann ausschalten */
    lampe->ausschalten();
    QCOMPARE(lampe->istEingeschaltet(), false);
}

/*
Test für Status abfragen
*/
void TestLampe::testStatusAbfragen()
{
    /* Initial ausgeschaltet */
    QCOMPARE(lampe->istEingeschaltet(), false);
    
    /* Nach Einschalten */
    lampe->einschalten();
    QCOMPARE(lampe->istEingeschaltet(), true);
    
    /* Nach Ausschalten */
    lampe->ausschalten();
    QCOMPARE(lampe->istEingeschaltet(), false);
}

/*
Test für mehrfaches Schalten
*/
void TestLampe::testMehrfachSchalten()
{
    /* Mehrfach einschalten */
    lampe->einschalten();
    lampe->einschalten();
    lampe->einschalten();
    
    QCOMPARE(lampe->istEingeschaltet(), true);
    
    /* Mehrfach ausschalten */
    lampe->ausschalten();
    lampe->ausschalten();
    lampe->ausschalten();
    
    QCOMPARE(lampe->istEingeschaltet(), false);
}

QTEST_APPLESS_MAIN(TestLampe); 