#pragma once
#include "Fernbedienung.h"
#include <vector>
class Aktoren {
private:
    bool if_activ;
public:
    Aktoren();
    virtual~Aktoren();
    std::vector<Fernbedienung * > Fernbedienung;
    void Anschalten();
    void ausschalten();
};

