#ifndef ANTENNE_H
#define ANTENNE_H
//create by Leonel on 23.04.2025

#include<aktoren.h>
#include<iostream>


class Antenne : public Aktoren
{
private:
    bool Status;
    float Frequenz;
public:
    float FrequnezWechseln(float);
    Antenne();   // konstruktor
    ~Antenne(); //Destruktor
};

#endif // ANTENNE_H
