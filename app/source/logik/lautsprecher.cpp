#include "Lautsprecher.h"
#include "aktoren.h"

Lautsprecher::Lautsprecher() 
    : istAn(false) {
}

Lautsprecher::~Lautsprecher() = default;

void Lautsprecher::einschalten() {
    istAn = true;
    Anschalten();
}

void Lautsprecher::ausschalten() {
    istAn = false;
    Aktoren::ausschalten();
}

bool Lautsprecher::istEingeschaltet() const {
    return istAn;
} 