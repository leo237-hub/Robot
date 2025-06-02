#pragma once
#include <QObject>
#include <QTimer>
#include <iostream>
#include "feuer.h"
#include <vector>
using namespace  std;
/*
Zweck und Verhalten der Simulationsklasse: 

Zweck: Um die Daten fuer die Sensoren zu erzeugen , ist eine Simulationsklasse gebraucht.

Verhalten: Die Simulationsklasse erzeugt bei instanziierung, die Objekte fuer die Verschiedene Attribute ( Feuer, Gasmappe ..), d.h. eine Schnitstelle mit der Verwaltung der Position/Umgebung ist notwendig. 
Nach instanziierung steht die Simulationsklasse zur verfuegung um die Daten abzufragen mit Obj.getData().
Fuer jedes attribut ist eine eigene Klasse notwendig.

*/
class Simulation : public QObject {
     Q_OBJECT
public:
    vector<Feuer*> gruppeFeuer;    
    explicit Simulation(QObject* parent = nullptr);
    float erzeugeTemperatur(const QPointF& objPosition);
    void addiereFeuerUmgebung(Feuer * addiereMich);
 /*
    TODO: 
    1. getter and setter Methods for each Attribute 
    2. generation function / setter function , for each Attribute
    3. In the constructor , the position and generation of the elements has to be handled ( where are the fires? how many fires?)
    4. There has to be some kind of logic makin the values fluctuate (fire dwindles down as time goes on)

    */
};

