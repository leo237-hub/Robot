#ifndef DCMOTOR_H
#define DCMOTOR_H
#include<iostream>
#include<vector>
#include "aktoren.h"
#include "ReturnHome.h"
#include "Dc-SignalInterpreter.h"
#include "selfcheck.h"   // to do : include Header Kettesensor
class dcMotor : public Aktoren {
private:
    int MotorNummer;
    float Leistung;
    float Winkel ;

public:
    dcMotor();
    ~dcMotor() override;
    std::vector<Selfcheck * > Selfcheck;
    std::vector<Dc_SignalInterpreter * > Dc_SignalInterpreter;
    //to do die Klasse Kettesensor instanzieren
    std::vector<ReturnHome * > ReturnHome;
    void vorgehen();
    void zuruektreten();
    void stoppen();
    // BestimmtenWinkelumdrehen
    float WinkelDrehen(float);
    // Drehzahleinstellen
    float Drehzahlaendern(float);
};
#endif // DCMOTOR_H
