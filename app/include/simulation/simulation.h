#pragma once
#include <QObject>
#include <QTimer>
#include <iostream>
#include "feuer.h"
#include "gasSimulationElement.h"
#include "wasserSimulationElement.h"
#include <vector>
#include <QGraphicsScene>
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
    vector<GasSimulationElement*> gruppeGasQuellen;
    vector<WasserSimulationElement*> gruppeWasserQuellen;
    vector<simulationElement*> Steine;
    vector<simulationElement*> Personen;

    explicit Simulation(QObject* parent = nullptr);
    void addiereFeuerUmgebung(Feuer * addiereMich);
    void addiereGasQuelleUmgebung(GasSimulationElement * addiereMich);
    void addiereWasserQuelleUmgebung(WasserSimulationElement * addiereMich);
    void addiereSteineUmgebung(simulationElement * addiereMich);
    void addierePersonUmgebung(simulationElement * addiereMich);
    void addiereElementeScene(QGraphicsScene * scene);
    float erzeugeTemperatur(const QPointF& objPosition); // temperatur sensor
    float erzeugeGasKonzentration(const QPointF& objPosition); // gas sensor
    float erzeugeWasserKonzentration(const QPointF& objPosition); // wasser sensor
    void aktualisierePosition(const QPointF& objPosition); // gps sensor

};

