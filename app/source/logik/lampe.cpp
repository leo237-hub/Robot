#include "lampe.h"
#include "aktoren.h"

Lampe::Lampe() 
    : istAn(false) {
}


Lampe::~Lampe() = default;


void Lampe::einschalten() {
    istAn = true;
    Anschalten();
}


void Lampe::ausschalten() {
    istAn = false;
    Aktoren::ausschalten();
}


bool Lampe::istEingeschaltet() const {
    return istAn;
}
