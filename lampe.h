#ifndef LAMPE_H
#define LAMPE_H

//create  by Leonel on 23.04.2025

#include <iostream>
#include "aktoren.h"



class Lampe : public Aktoren
{
private:
    bool Status ; //an? aus?
    int Helligkeit;
public:
    float HelligkeitAnpassen(float Helligkeit);

    Lampe(); //Konstruktor
    ~Lampe();//destruktor
};

#endif // LAMPE_H
