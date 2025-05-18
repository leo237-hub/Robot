#ifndef ANTENNE_H
#define ANTENNE_H
#include<aktoren.h>
#include<iostream>
class Antenne : public Aktoren {
private:
    bool Status;
    float Frequenz;

public:
    Antenne();
    ~Antenne()override;
    float FrequnezWechseln(float);

};
#endif // ANTENNE_H
