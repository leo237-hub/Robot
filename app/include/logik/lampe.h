#pragma once 
#include <iostream>
#include "aktoren.h"

/*
Zweck und Verhalten der Lampe-Klasse:

Zweck: Steuerung der Beleuchtung des ResQ-Roboters für bessere Sichtbarkeit in dunklen Umgebungen.

Verhalten: Die Lampe-Klasse erbt von Aktoren und verwaltet den Ein/Aus-Zustand der Beleuchtung.
Sie kann über die Fernbedienung gesteuert werden und bietet eine einfache Schnittstelle zum
Ein- und Ausschalten der Lampen.
*/
class Lampe : public Aktoren {
private:
    bool istAn;

public:
    Lampe();
    ~Lampe() override;
    void einschalten();
    void ausschalten();
    bool istEingeschaltet() const;
};

