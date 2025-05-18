#pragma once
#include <iostream>
#include <fire.h>
using namespace  std;

/*
Zweck und Verhalten der Positionsklasse

Zweck: Um die x,y,z Position , einer belibigen Klasse zu speichern.
Verhalten: Die klasse speichert die Position in 3 verschieden Attribute, die man mit setter und getter Verwalten kann.
Die Klasse stellt zur Verfuegung die moeglichkeit zwei Positionen im Bezug des abstand zu vergleichen.

*/

class Position {
private:    
    float xPosition;
    float yPosition;
    float zPosition;
public:
float holexPosition();
float holeyPosition();
float holezPosition();
float vergleichePosition(const Position& anderePosition);

    
    

};