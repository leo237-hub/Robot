#pragma once
#include<string>
using namespace std;

/*
Zweck und Verhalten der SensorDisplay-Klasse

Zweck:
Stellt Sensordaten und Kamerabilder grafisch dar und ermöglicht deren Aktualisierung.

Verhalten:
Zeigt Live-Kamerabilder und Sensordaten an, aktualisiert die Anzeige und steuert die Darstellung.
*/

class SensorDisplay {

private:
    string SensorDaten;

public:
    SensorDisplay();
    virtual ~ SensorDisplay();
    void kameraLiveStarten() const;
    void kameraLiveStoppen() const;
    void sensorInformationenAnzeigen() const;
    void gesamteDarstellungAktualisieren() const;
}; 