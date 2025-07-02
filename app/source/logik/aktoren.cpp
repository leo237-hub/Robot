#include "aktoren.h"
#include <iostream>
/*
void Aktoren::Anschalten() {}
void Aktoren::ausschalten(){}
Aktoren::Aktoren(){}
virtual Aktoren::~Aktoren(){}
*/
Aktoren::Aktoren()
    : active(false) {}

Aktoren::~Aktoren() = default;  

void Aktoren::Anschalten() {
    active = true;
}

void Aktoren::ausschalten() {
    active = false;
}
