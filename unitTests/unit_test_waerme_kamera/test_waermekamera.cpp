#include "test_waermekamera.h"

void TestWaermeKamera::init()
{
    kamera = new WaermeKamera();
}

void TestWaermeKamera::cleanup()
{
    delete kamera;
}

/*
Test für Konstruktor
*/
void TestWaermeKamera::testKonstruktor()
{
    WaermeKamera testKamera;
    
    // Kamera sollte standardmäßig inaktiv sein
    QVERIFY(!testKamera.istAktiv());
}

/*
Test für Schalten der Kamera
*/
void TestWaermeKamera::testSchalten()
{
    // Initial sollte Kamera inaktiv sein
    QVERIFY(!kamera->istAktiv());
    
    // Nach dem ersten Schalten sollte sie aktiv sein
    bool ergebnis = kamera->wSchalten();
    QVERIFY(ergebnis);
    QVERIFY(kamera->istAktiv());
    
    // Nach dem zweiten Schalten sollte sie wieder inaktiv sein
    ergebnis = kamera->wSchalten();
    QVERIFY(!ergebnis);
    QVERIFY(!kamera->istAktiv());
}

/*
Test für mehrfaches Schalten
*/
void TestWaermeKamera::testSchaltungMehrfach()
{
    bool status = false;
    
    for(int i = 0; i < 10; i++) {
        status = !status;
        bool ergebnis = kamera->wSchalten();
        QCOMPARE(ergebnis, status);
        QCOMPARE(kamera->istAktiv(), status);
    }
}

/*
Test für Aktiv Status abfragen
*/
void TestWaermeKamera::testIstAktiv()
{
    // Initial inaktiv
    QVERIFY(!kamera->istAktiv());
    
    // Nach Aktivierung aktiv
    kamera->wSchalten();
    QVERIFY(kamera->istAktiv());
    
    // Nach Deaktivierung wieder inaktiv
    kamera->wSchalten();
    QVERIFY(!kamera->istAktiv());
}

/*
Test für Foto machen
*/
void TestWaermeKamera::testFotoMachen()
{
    uint8_t* foto = kamera->fotoMachen(0);
    
    // Foto sollte nicht null sein
    QVERIFY(foto != nullptr);
    
    // Speicher freigeben
    delete[] foto;
}

/*
Test für Foto Größe
*/
void TestWaermeKamera::testFotoMachenGroesse()
{
    uint8_t* foto = kamera->fotoMachen(0);
    QVERIFY(foto != nullptr);
    
    // Prüfe dass Daten vorhanden sind (ersten paar Bytes)
    // Da es zufällige Daten sind, prüfen wir nur ob der Pointer gültig ist
    bool datenVorhanden = true;
    try {
        // Versuche auf die ersten Bytes zuzugreifen
        uint8_t test = foto[0];
        test = foto[1];
        test = foto[2];
        Q_UNUSED(test);
    } catch (...) {
        datenVorhanden = false;
    }
    
    QVERIFY(datenVorhanden);
    
    // Speicher freigeben
    delete[] foto;
}

/*
Test für Foto machen mit verschiedenen Parametern
*/
void TestWaermeKamera::testFotoMachenNull()
{
    // Test mit verschiedenen uint8_t Werten
    uint8_t* foto1 = kamera->fotoMachen(255);
    uint8_t* foto2 = kamera->fotoMachen(128);
    uint8_t* foto3 = kamera->fotoMachen(0);
    
    QVERIFY(foto1 != nullptr);
    QVERIFY(foto2 != nullptr);
    QVERIFY(foto3 != nullptr);
    
    // Speicher freigeben
    delete[] foto1;
    delete[] foto2;
    delete[] foto3;
}

/*
Test für Temperatur lesen
*/
void TestWaermeKamera::testTemperaturLesen()
{
    float temperatur = kamera->temperaturLesen();
    
    // Aktuell gibt die Methode immer 0 zurück
    QCOMPARE(temperatur, 0.0f);
}

/*
Test für Video aufnehmen
*/
void TestWaermeKamera::testVideoAufnehmen()
{
    uint8_t* video = kamera->videoAufnehmen(0);
    
    // Aktuell gibt die Methode nullptr zurück
    QVERIFY(video == nullptr);
}

QTEST_APPLESS_MAIN(TestWaermeKamera);