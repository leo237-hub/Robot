#ifndef AKTOREN_H
#define AKTOREN_H
#include "Fernbedienung.h"
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
#endif // AKTOREN_H
