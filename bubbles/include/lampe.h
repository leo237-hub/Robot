#ifndef LAMPE_H
#define LAMPE_H
#include <iostream>
#include "aktoren.h"
class Lampe : public Aktoren {
private:
    //an? aus?
    bool Status ;
    int Helligkeit;

public:
    Lampe();
    ~Lampe();
    float HelligkeitAnpassen(float);
};
#endif // LAMPE_H
