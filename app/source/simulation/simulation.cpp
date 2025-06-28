#include "simulation.h"
#include "position.h"
#include "feuer.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <cmath>
Simulation::Simulation(QObject* parent)
    : QObject(parent) {}
float Simulation::erzeugeTemperatur(const QPointF& objPosition) {
    /*
    Diese Funktion iteriert durch alle existierende Feuern und berechnet die Temperatur mit gewichtung nach den Abstand.
    Falls es keine Feuern gibt ,  dann gibt diese Funktion die Raumtemperatur zurueck.
    */

    float raumTemperatur = 20.0f;
    float maxTemperatur = raumTemperatur;
    float gesamtTemperatur = 0;
    float gewichteteTemperatur;
    
    if(gruppeFeuer.empty())
    {
        return raumTemperatur;
    }

    for(auto& feuer : this->gruppeFeuer) {
        float abstand = feuer->berechneAbstand(objPosition);
        
        // Verhindere Division durch Null und setze Mindestabstand
        if(abstand < 1.0f) {
            abstand = 1.0f; // Mindestabstand von 1 Einheit
        }
        
        // Normalisiere Abstand (30 Einheiten = maximale Reichweite)
        float normalisierterAbstand = abstand / 30.0f;
        
        // Berechne gewichtete Temperatur mit quadratischem Abfall
        gewichteteTemperatur = feuer->holeTemperatur() / (normalisierterAbstand * normalisierterAbstand);
        
        // Begrenze die maximale Temperatur pro Feuer
        if(gewichteteTemperatur > feuer->holeTemperatur()) {
            gewichteteTemperatur = feuer->holeTemperatur();
        }
        
        // Finde die höchste Temperatur
        if(gewichteteTemperatur > maxTemperatur) {
            maxTemperatur = gewichteteTemperatur;
        }
        
        // Summiere alle anderen Temperaturen für Hintergrundwärme
        gesamtTemperatur += gewichteteTemperatur;
    }

    // Berechne finale Temperatur mit Begrenzung
    float finaleTemperatur = maxTemperatur + (0.1f * gesamtTemperatur);
    
    // Begrenze die Temperatur auf realistische Werte (max 500°C)
    if(finaleTemperatur > 500.0f) {
        finaleTemperatur = 500.0f;
    }
    
    return finaleTemperatur;
}

void Simulation::addiereFeuerUmgebung(Feuer *addiereMich) {
    this->gruppeFeuer.push_back(addiereMich);
}

void Simulation::addiereSteineUmgebung(simulationElement *addiereMich) {
    this->Steine.push_back(addiereMich);
}

void Simulation::addierePersonUmgebung(simulationElement *addiereMich) {
    this->Personen.push_back(addiereMich);
}

void Simulation::addiereElementeScene(QGraphicsScene *scene) {
    for (auto& feuer : this->gruppeFeuer) {
        scene->addItem(feuer);
    }
    for (auto& stein : this->Steine) {
        scene->addItem(stein);
    }
    for (auto& person : this->Personen) {
        scene->addItem(person);
    }
}

