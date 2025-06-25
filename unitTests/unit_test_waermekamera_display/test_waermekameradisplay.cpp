#include "test_waermekameradisplay.h"

void TestWaermekameraDisplay::init()
{
    testLabel = new QLabel();
    display = new WaermekameraDisplay(testLabel);
    testDaten = erstelleTestBildDaten();
}

void TestWaermekameraDisplay::cleanup()
{
    delete display;
    delete testLabel;
    delete[] testDaten;
}

/*
Test für Wärmebild anzeigen ohne Fehler
*/
void TestWaermekameraDisplay::testWaermeBildAnzeigenOhneError()
{
    // Test sollte ohne Crash oder Exception ausgeführt werden
    bool erfolgreich = true;
    try {
        display->waermeBildAnzeigen(testDaten);
    } catch (...) {
        erfolgreich = false;
    }
    
    QVERIFY(erfolgreich);
}

/*
Test für Wärmebild anzeigen mit validen Daten
*/
void TestWaermekameraDisplay::testWaermeBildAnzeigenMitValidenDaten()
{
    display->waermeBildAnzeigen(testDaten);
    
    // Label sollte nach dem Anzeigen ein Pixmap haben
    QVERIFY(!testLabel->pixmap().isNull());
}

/*
Test für Wärmebild anzeigen mit Null Pointer
*/
void TestWaermekameraDisplay::testWaermeBildAnzeigenMitNullPointer()
{
    // Test mit nullptr - sollte nicht crashen
    bool testErfolgreich = true;
    try {
        display->waermeBildAnzeigen(nullptr);
    } catch (...) {
        testErfolgreich = false;
    }
    
    // Der Test prüft nur, dass kein Crash auftritt
    QVERIFY(testErfolgreich);
}

/*
Test für Label hat Pixmap nach Anzeige
*/
void TestWaermekameraDisplay::testLabelHatPixmapNachAnzeige()
{
    display->waermeBildAnzeigen(testDaten);
    
    // Überprüfe, dass scaledContents nach Anzeigen aktiviert ist
    QVERIFY(testLabel->hasScaledContents());
    
    // Label sollte ein Pixmap haben
    QVERIFY(!testLabel->pixmap().isNull());
}

/*
Hilfsmethode zum Erstellen von Testbilddaten
*/
uint8_t* TestWaermekameraDisplay::erstelleTestBildDaten()
{
    int width = 630;
    int height = 480;
    int size = width * height * 3; // RGB
    
    uint8_t* data = new uint8_t[size];
    
    // Einfaches Testmuster erstellen
    for (int i = 0; i < size; i += 3) {
        data[i]     = 255;  // Rot
        data[i + 1] = 128;  // Grün
        data[i + 2] = 0;    // Blau
    }
    
    return data;
}

QTEST_MAIN(TestWaermekameraDisplay);