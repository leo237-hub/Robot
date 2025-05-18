#include "../include/aktoren.h"
#include <iostream>


/*
void Aktoren::Anschalten() {}
void Aktoren::ausschalten(){}

Aktoren::Aktoren(){}
virtual Aktoren::~Aktoren(){}

*/
Aktoren::Aktoren()
    : if_activ(false) {}

Aktoren::~Aktoren() = default;  // virtuelle Destruktor-Implementierung

void Aktoren::Anschalten() {
    if_activ = true;
}

void Aktoren::ausschalten() {
    if_activ = false;
}
