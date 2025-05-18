#pragma once
#include <iostream>
#include <fire.h>
#include <position.h>
using namespace  std;


/*
Zweck und Verhalten der Feuerklasse: 

Zweck: Erzeugt die Daten fuer den Feuer in der Umgebung.

Verhalten: Beinhaltet die Position des Feuer und die aktuelle Temperatur. Diese Temperatur kann man sich von der Klasse ausgeben lassen.
Die Temperatur geht mit der Zeit runter,wie bei einen normalen Feuer.

*/

class Feuer {
private:
    Position feuerPosition;
    float Temperatur;


public:
    void aktualisiereTemperature();
    float holeTemperatur();
    Position holePosition();
    void setzePosition(const float& xPosition,const float& yPosition, const float& zPosition);


};
