#pragma once
#include <string>

using namespace std;

/*
Zweck und Verhalten der PaketFach-Klasse:

Zweck: Verwaltung des Paketfachs für die Lieferung von Hilfspaketen (Erste-Hilfe-Kit, Wasser, Gasmaske etc.) 


Verhalten: Das Paketfach kann geöffnet und geschlossen werden. Es verwaltet seinen aktuellen Zustand 
(OFFEN/GESCHLOSSEN).
*/
class PaketFach {
private:
    string zustand;

public:
    PaketFach();
    ~PaketFach();
    
    void Oeffnen();
    void Schliessen();
    
    string holeZustand() const;

};