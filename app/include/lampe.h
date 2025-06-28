#pragma once 
#include <iostream>
#include "aktoren.h"
class Lampe : public Aktoren {
private:
   
    bool Status ;
    int Helligkeit;

public:
    Lampe();
    ~Lampe() override;
    float HelligkeitAnpassen(float);
};

