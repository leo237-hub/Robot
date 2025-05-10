#ifndef DREHMOTOR_H
#define DREHMOTOR_H
#include "aktoren.h"
//create by Leonel on 23.04.2025

class Drehmotor : public Aktoren

{
    float MaxDrehzahl, Aktuelwinkel, Leistung, Winkel;

public:
    Drehmotor();  //konstruktor
    virtual ~Drehmotor(); //destuktor

    float DrehWinkel(float Winkel); //BestimmtenWinkelUmdrehen
    float DrehZahl(float ZAhl);     //DrehzahlEinstellen
    void Stoppen();


};
//Fehlt noch die Methode Ein-Ausschalten von der Klasse Aktoren
#endif // DREHMOTOR_H
