#pragma once

class Lautsprecher  {
private:
    int Lautstaerke;
    bool Starus;
    float TonFrequenz;

public:
    Lautsprecher();
    virtual ~Lautsprecher();
    void spracheAusgeben() const;
    void lautStaerkeAnpassen() const;

};

