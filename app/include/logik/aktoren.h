#pragma once

/*
Zweck und Verhalten der Aktoren-Klasse:

Zweck: Basisklasse für alle Aktoren im ResQ-Roboter.
Verwaltet den grundlegenden Ein/Aus-Zustand aller Aktoren.

Verhalten: Die Aktoren-Klasse bietet eine gemeinsame Schnittstelle für alle Aktoren
mit grundlegenden Ein- und Ausschaltfunktionen.
*/
class Aktoren {
private:
    bool active;

public:
    Aktoren();
    virtual ~Aktoren();
    void Anschalten();
    void ausschalten();
};

