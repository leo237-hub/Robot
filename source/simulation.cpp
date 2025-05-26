#include "../include/simulation/simulation.h"
#include "../include/simulation/position.h"
#include "../include/simulation/feuer.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <cmath>
Simulation::Simulation(QObject* parent)
    : QObject(parent){}
float Simulation::erzeugeTemperatur(const QPointF& objPosition){
/*
Diese Funktion iteriert durch alle existierende Feuern und berechnet die Temperatur mit gewichtung nach den Abstand.
Falls es keine Feuern gibt ,  dann gibt diese Funktion die Raumtemperatur zurueck.
*/
float maxTemperatur = 20;
float gesamtTemperatur = 0;
float gewichteteTemperatur;


if(sizeof(gruppeFeuer) == 0)
{
    return 20;
}

for(auto& feuer : this->gruppeFeuer){
    
    float abstand = feuer->berechneAbstand(objPosition)/30;

    if(abstand == 0){
        gewichteteTemperatur = feuer->holeTemperatur();
    }
    else{
        gewichteteTemperatur = feuer->holeTemperatur()/(abstand*abstand);
    }

    if(maxTemperatur < gewichteteTemperatur){
        maxTemperatur = gewichteteTemperatur;
    }
    else{
        gesamtTemperatur += gewichteteTemperatur;
    }
    
}

return maxTemperatur + (0.15*gesamtTemperatur);
}

void Simulation::addiereFeuerUmgebung(Feuer *addiereMich){
    this->gruppeFeuer.push_back(addiereMich);
}



