#pragma once

/*
Zweck und Verhalten der Kettensensor-Klasse

Zweck:
Erfasst die Anzahl der Kettengliederbewegungen zur Überwachung der Fortbewegung.

Verhalten:
Speichert und aktualisiert die Schrittanzahl, stellt Methoden zum Hinzufügen und Abfragen bereit.
*/

class Kettensensor {
private:
    int AnzahlSchritte;

public:
    Kettensensor(int initialSchritte = 0);
    int HoleSchritte() const;
    void SchrittHinzufuegen(int schritte);
};





