#pragma once
#include <QtTest/QtTest>
#include <QLabel>
#include <QPixmap>
#include "WaermekameraDisplay.h"

/*
Unit Test für WaermekameraDisplay Klasse
Getestet:
- Wärmebild anzeigen Funktionalität ohne visuelle Ausgabe
- Korrekte Verarbeitung von uint8_t Daten
- QLabel Integration ohne tatsächliche Anzeige
- Fehlverhalten mit ungültigen Daten
*/

class TestWaermekameraDisplay : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void cleanup();
    
    void testWaermeBildAnzeigenOhneError();
    void testWaermeBildAnzeigenMitValidenDaten();
    void testWaermeBildAnzeigenMitNullPointer();
    void testLabelHatPixmapNachAnzeige();

private:
    WaermekameraDisplay* display;
    QLabel* testLabel;
    uint8_t* testDaten;
    
    uint8_t* erstelleTestBildDaten();
};