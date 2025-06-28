#pragma once
#include <stdbool.h>
#include <string>
#include "knopf.h"
#include <array>
#define ANZAHLKNOEPFE 6
using namespace std;

/*
Zweck und Verhalten der FernbedienungInterpreter-Klasse:

Zweck: Interpretation und Verwaltung der Knöpfe auf der Fernbedienung. Diese Klasse dient als Schnittstelle 
zwischen der physischen Eingabe (Knopfdruck) und der logischen Verarbeitung im System.

Verhalten: Die Klasse verwaltet ein Array von 6 Knöpfen, die verschiedene Funktionen repräsentieren 
(Bewegung, Paketfach, Self-Check). Sie kann den Zustand der Knöpfe lesen und Signale validieren.
*/
class FernbedienungInterpreter {
private:
    
    array<Knopf, ANZAHLKNOEPFE> knoepfe;
    
    void initialisiereKnoepfe();

public:
    FernbedienungInterpreter();
    ~FernbedienungInterpreter() = default;
    
    Knopf* leseKnoepfe();
    bool schickSignal(Knopf& knopf);
    void resetAlleKnoepfe();
};
