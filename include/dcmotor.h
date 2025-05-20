#ifndef DCMOTOR_H
#define DCMOTOR_H
#include<iostream>
#include<vector>
#include "aktoren.h"
#include "ReturnHome.h"
#include "Dc-SignalInterpreter.h"
#include "selfcheck.h"
// to do : include Header Kettesensor

class dcMotor : public Aktoren {
private:
    //Drehzahl (z. B. von 0.0 bis 1.0)
    float Leistung;
    //1 = vorwärt -1 = rückwärts 0 = stop
    int Richtung ;

public:
    dcMotor();
    ~dcMotor() override;
    std::vector<Selfcheck * > Selfcheck;
    std::vector<Dc_SignalInterpreter * > Dc_SignalInterpreter;
    //  std::vector<roboter *> roboter;
    //to do die Klasse Kettesensor instanzieren
    std::vector<ReturnHome * > ReturnHome;
    //setzt Leistung und Richtung
    void drehen(float, int);
    //setzt Leistung auf 0 und Richtung auf 0
    void stoppen();
    float getLeistung() const;
    int getRichtung() const ;
};
#endif // DCMOTOR_H
