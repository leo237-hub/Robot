#include "test_knopf.h"

void TestKnopf::init()
{
    knopf = new Knopf();
}

void TestKnopf::cleanup()
{
    delete knopf;
}

/*
Test für Standard-Konstruktor
*/
void TestKnopf::testKonstruktorStandard()
{
    Knopf neuerKnopf;
    
    /* Knopf sollte initial nicht gedrückt sein */
    QCOMPARE(neuerKnopf.holeStatus(), false);
    QCOMPARE(neuerKnopf.holeID(), std::string(""));
}

/*
Test für Konstruktor mit Parametern
*/
void TestKnopf::testKonstruktorMitParametern()
{
    Knopf gedrueckterKnopf(true, "TEST_KNOPF");
    
    QCOMPARE(gedrueckterKnopf.holeStatus(), true);
    QCOMPARE(gedrueckterKnopf.holeID(), std::string("TEST_KNOPF"));
}

/*
Test für Status setzen
*/
void TestKnopf::testStatusSetzen()
{
    knopf->setzeStatus(true);
    QCOMPARE(knopf->holeStatus(), true);
    
    knopf->setzeStatus(false);
    QCOMPARE(knopf->holeStatus(), false);
}

/*
Test für Status abfragen
*/
void TestKnopf::testStatusAbfragen()
{
    /* Initial nicht gedrückt */
    QCOMPARE(knopf->holeStatus(), false);
    
    /* Nach Drücken */
    knopf->setzeStatus(true);
    QCOMPARE(knopf->holeStatus(), true);
    
    /* Nach Loslassen */
    knopf->setzeStatus(false);
    QCOMPARE(knopf->holeStatus(), false);
}

/*
Test für ID abfragen
*/
void TestKnopf::testIDAbfragen()
{
    /* Standard-Konstruktor sollte leere ID haben */
    QCOMPARE(knopf->holeID(), std::string(""));
    
    /* Knopf mit ID erstellen */
    Knopf knopfMitID(false, "START_KNOPF");
    QCOMPARE(knopfMitID.holeID(), std::string("START_KNOPF"));
}

QTEST_APPLESS_MAIN(TestKnopf); 