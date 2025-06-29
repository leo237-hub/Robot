#pragma once
#include <QtTest/QtTest>
#include "Waermekamera.h"

/*
Unit Test für WaermeKamera Klasse
Getestet:
- Konstruktor und Destruktor
- Ein-/Ausschalten der Kamera
- Foto machen und Datenvalidierung
- Temperatur lesen
- Video aufnehmen
- Aktiv-Status abfragen
*/

class TestWaermeKamera : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void cleanup();
    
    void testKonstruktor();
    void testSchalten();
    void testSchaltungMehrfach();
    
    void testIstAktiv();
    void testFotoMachen();
    void testFotoMachenGroesse();
    void testFotoMachenNull();
    
    void testTemperaturLesen();
    void testVideoAufnehmen();

private:
    WaermeKamera* kamera;
};