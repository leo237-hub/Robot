#pragma once

#include <QObject>
#include <QLabel>
#include <cstdint>

/*
Zweck und Verhalten der WaermekameraDisplay-Klasse

Zweck:
Stellt die Anzeige der Wärmebilddaten auf einem QLabel bereit.

Verhalten:
Empfängt Wärmebilddaten und aktualisiert die grafische Anzeige entsprechend.
*/

class WaermekameraDisplay : public QObject {
    Q_OBJECT

public:
    explicit WaermekameraDisplay(QLabel* anzeigeLabel, QObject* parent = nullptr);
    void waermeBildAnzeigen(uint8_t* data);

private:
    QLabel* label;
}; 