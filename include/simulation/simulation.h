#pragma once
#include <QObject>
#include <QTimer>
#include <iostream>
#include "feuer.h"
#include <vector>
#include <QgraphicsScene>
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
    vector<simulationElement*> Steine; 
    vector<simulationElement*> Personen;
    
    explicit Simulation(QObject* parent = nullptr);
    void addiereFeuerUmgebung(Feuer * addiereMich);
    void addiereSteineUmgebung(simulationElement * addiereMich); 
    void addierePersonUmgebung(simulationElement * addiereMich);
    void addiereElementeScene(QGraphicsScene * scene);
    float erzeugeTemperatur(const QPointF& objPosition); // temperatur sensor
    void aktualisierePosition(const QPointF& objPosition); // gps sensor

};

