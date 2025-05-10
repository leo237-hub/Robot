#ifndef DREHMOTOR_H
#define DREHMOTOR_H
#include "aktoren.h"
class Drehmotor : public Aktoren {
private:
    float MaxDrehzahl;
    float Aktuelwinkel;
    float Leistung;
    float Winkel;

public:
    float DrehWinkel(float Winkel); //BestimmtenWinkelUmdrehen
    float DrehZahl(float ZAhl);     //DrehzahlEinstellen
    void Stoppen();


};
//Fehlt noch die Methode Ein-Ausschalten von der Klasse Aktoren
#endif // DREHMOTOR_H
