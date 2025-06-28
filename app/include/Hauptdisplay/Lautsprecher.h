#pragma once
#include "aktoren.h"

/*
Zweck und Verhalten der Lautsprecher-Klasse:

Zweck: Steuerung der Audio-Ausgabe des ResQ-Roboters für Sprachausgabe und akustische Signale.

Verhalten: Die Lautsprecher-Klasse erbt von Aktoren und verwaltet den Ein/Aus-Zustand der Audio-Ausgabe.
Sie kann über die Fernbedienung gesteuert werden und bietet eine einfache Schnittstelle zum
Ein- und Ausschalten der Lautsprecher.
*/
class Lautsprecher : public Aktoren {
private:
    bool istAn;

public:
    Lautsprecher();
    ~Lautsprecher() override;
    void einschalten();
    void ausschalten();
    bool istEingeschaltet() const;
};

