#ifndef AKTOREN_H
#define AKTOREN_H

//create by Leonel on 23.04.2025
class Aktoren
{
private:
    int ID;
    bool if_activ;

public:
    void Anschalten();
    void ausschalten();

    Aktoren();  //construktor

    ~Aktoren(); //Detructor
};

#endif // AKTOREN_H
