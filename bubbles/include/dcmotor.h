#ifndef DCMOTOR_H
#define DCMOTOR_H
#
#include "aktoren.h"

class dcMotor : public Aktoren
{
private:

    int MotorNummer;
    float Leistung;
    float Winkel ;


public:
    void vorgehen();
    void zuruektreten();
    void Halten();
    float WinkelDrehen(float);        // BestimmtenWinkelumdrehen
    float Drehzahlaendern(float);     // Drehzahleinstellen

    dcMotor();
    ~dcMotor();
};

#endif // DCMOTOR_H
