#ifndef AKTOREN_H
#define AKTOREN_H
#include "Fernbedienung.h"
#include <vector>
<<<<<<< HEAD
=======

>>>>>>> 91474d4ac5f43b4bad4c0ce0b39a1073fcd7e99e
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
