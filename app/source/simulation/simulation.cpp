#include "simulation.h"
#include "position.h"
#include "feuer.h"
#include "gasSimulationElement.h"
#include "wasserSimulationElement.h"
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

float Simulation::erzeugeGasKonzentration(const QPointF& objPosition) {
    /*
    Diese Funktion iteriert durch alle existierenden Gasquellen und berechnet die Gas-Konzentration mit gewichtung nach den Abstand.
    Falls es keine Gasquellen gibt, dann gibt diese Funktion die Hintergrund-Gaskonzentration zurück.
    */

    float hintergrundGasKonzentration = 5.0f; // 5% Hintergrund-Gaskonzentration
    float maxGasKonzentration = hintergrundGasKonzentration;
    float gesamtGasKonzentration = 0;
    float gewichteteGasKonzentration;
    
    if(gruppeGasQuellen.empty()) {
        return hintergrundGasKonzentration;
    }

    for(auto& gasQuelle : this->gruppeGasQuellen) {
        float abstand = gasQuelle->berechneAbstand(objPosition);
        
        // Verhindere Division durch Null und setze Mindestabstand
        if(abstand < 1.0f) {
            abstand = 1.0f; // Mindestabstand von 1 Einheit
        }
        
        // Normalisiere Abstand (50 Einheiten = maximale Reichweite für Gas)
        float normalisierterAbstand = abstand / 50.0f;
        
        // Berechne gewichtete Gas-Konzentration mit quadratischem Abfall
        gewichteteGasKonzentration = gasQuelle->holeGasKonzentration() / (normalisierterAbstand * normalisierterAbstand);
        
        // Begrenze die maximale Gas-Konzentration pro Quelle
        if(gewichteteGasKonzentration > gasQuelle->holeGasKonzentration()) {
            gewichteteGasKonzentration = gasQuelle->holeGasKonzentration();
        }
        
        // Finde die höchste Gas-Konzentration
        if(gewichteteGasKonzentration > maxGasKonzentration) {
            maxGasKonzentration = gewichteteGasKonzentration;
        }
        
        // Summiere alle anderen Gas-Konzentrationen für Hintergrund
        gesamtGasKonzentration += gewichteteGasKonzentration;
    }

    // Berechne finale Gas-Konzentration mit Begrenzung
    float finaleGasKonzentration = maxGasKonzentration + (0.1f * gesamtGasKonzentration);
    
    // Begrenze die Gas-Konzentration auf realistische Werte (max 100%)
    if(finaleGasKonzentration > 100.0f) {
        finaleGasKonzentration = 100.0f;
    }
    
    return finaleGasKonzentration;
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

void Simulation::addiereGasQuelleUmgebung(GasSimulationElement *addiereMich) {
    this->gruppeGasQuellen.push_back(addiereMich);
}

void Simulation::addiereWasserQuelleUmgebung(WasserSimulationElement *addiereMich) {
    this->gruppeWasserQuellen.push_back(addiereMich);
}

void Simulation::addiereElementeScene(QGraphicsScene *scene) {
    for (auto& feuer : this->gruppeFeuer) {
        scene->addItem(feuer);
    }
    for (auto& gasQuelle : this->gruppeGasQuellen) {
        scene->addItem(gasQuelle);
    }
    for (auto& wasserQuelle : this->gruppeWasserQuellen) {
        scene->addItem(wasserQuelle);
    }
    for (auto& stein : this->Steine) {
        scene->addItem(stein);
    }
    for (auto& person : this->Personen) {
        scene->addItem(person);
    }
}

float Simulation::erzeugeWasserKonzentration(const QPointF& objPosition) {
    /*
    Diese Funktion iteriert durch alle existierenden Wasserquellen und berechnet die Wasser-Konzentration/Luftfeuchtigkeit mit gewichtung nach den Abstand.
    Falls es keine Wasserquellen gibt, dann gibt diese Funktion die Hintergrund-Wasser-Konzentration zurück.
    */

    float hintergrundWasserKonzentration = 30.0f; // 30% Standard-Luftfeuchtigkeit (abbassato da 50%)
    float maxWasserKonzentration = hintergrundWasserKonzentration;
    float gesamtWasserKonzentration = 0;
    float gewichteteWasserKonzentration;
    
    if(gruppeWasserQuellen.empty()) {
        return hintergrundWasserKonzentration;
    }

    for(auto& wasserQuelle : this->gruppeWasserQuellen) {
        float abstand = wasserQuelle->berechneAbstand(objPosition);
        
        // Verhindere Division durch Null und setze Mindestabstand
        if(abstand < 1.0f) {
            abstand = 1.0f; // Mindestabstand von 1 Einheit
        }
        
        // Normalisiere Abstand (40 Einheiten = maximale Reichweite für Wasser)
        float normalisierterAbstand = abstand / 40.0f;
        
        // Berechne gewichtete Wasser-Konzentration mit quadratischem Abfall
        gewichteteWasserKonzentration = wasserQuelle->holeWasserKonzentration() / (normalisierterAbstand * normalisierterAbstand);
        
        // Begrenze die maximale Wasser-Konzentration pro Quelle
        if(gewichteteWasserKonzentration > wasserQuelle->holeWasserKonzentration()) {
            gewichteteWasserKonzentration = wasserQuelle->holeWasserKonzentration();
        }
        
        // Finde die höchste Wasser-Konzentration
        if(gewichteteWasserKonzentration > maxWasserKonzentration) {
            maxWasserKonzentration = gewichteteWasserKonzentration;
        }
        
        // Summiere alle anderen Wasser-Konzentrationen für Hintergrund
        gesamtWasserKonzentration += gewichteteWasserKonzentration;
    }

    // Berechne finale Wasser-Konzentration mit Begrenzung
    float finaleWasserKonzentration = maxWasserKonzentration + (0.1f * gesamtWasserKonzentration);
    
    // Begrenze die Wasser-Konzentration auf realistische Werte (0-100%)
    if(finaleWasserKonzentration < 0.0f) {
        finaleWasserKonzentration = 0.0f;
    } else if(finaleWasserKonzentration > 100.0f) {
        finaleWasserKonzentration = 100.0f;
    }
    
    return finaleWasserKonzentration;
}

