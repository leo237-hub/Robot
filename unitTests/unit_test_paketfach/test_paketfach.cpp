#include "test_paketfach.h"

void TestPaketfach::init()
{
    paketfach = new PaketFach();
}

void TestPaketfach::cleanup()
{
    delete paketfach;
}

/*
Test für Konstruktor
*/
void TestPaketfach::testKonstruktor()
{
    PaketFach neuesPaketfach;
    
    /* Paketfach sollte initial geschlossen sein */
    QCOMPARE(neuesPaketfach.holeZustand(), std::string("GESCHLOSSEN"));
}

/*
Test für Öffnen
*/
void TestPaketfach::testOeffnen()
{
    paketfach->Oeffnen();
    
    QCOMPARE(paketfach->holeZustand(), std::string("OFFEN"));
}

/*
Test für Schließen
*/
void TestPaketfach::testSchliessen()
{
    /* Erst öffnen */
    paketfach->Oeffnen();
    QCOMPARE(paketfach->holeZustand(), std::string("OFFEN"));
    
    /* Dann schließen */
    paketfach->Schliessen();
    QCOMPARE(paketfach->holeZustand(), std::string("GESCHLOSSEN"));
}

/*
Test für Zustand abfragen
*/
void TestPaketfach::testZustandAbfragen()
{
    /* Initial geschlossen */
    QCOMPARE(paketfach->holeZustand(), std::string("GESCHLOSSEN"));
    
    /* Nach Öffnen */
    paketfach->Oeffnen();
    QCOMPARE(paketfach->holeZustand(), std::string("OFFEN"));
    
    /* Nach Schließen */
    paketfach->Schliessen();
    QCOMPARE(paketfach->holeZustand(), std::string("GESCHLOSSEN"));
}

/*
Test für mehrfaches Öffnen und Schließen
*/
void TestPaketfach::testMehrfachOeffnenSchliessen()
{
    /* Mehrfach öffnen */
    paketfach->Oeffnen();
    paketfach->Oeffnen();
    paketfach->Oeffnen();
    
    QCOMPARE(paketfach->holeZustand(), std::string("OFFEN"));
    
    /* Mehrfach schließen */
    paketfach->Schliessen();
    paketfach->Schliessen();
    paketfach->Schliessen();
    
    QCOMPARE(paketfach->holeZustand(), std::string("GESCHLOSSEN"));
}

QTEST_APPLESS_MAIN(TestPaketfach); 