#include "../include/simulation/simulation.h"
#include "../include/simulation/position.h"
#include "../include/simulation/feuer.h"

Simulation::erzeugeTemperatur(const Position& anderePosition){
/*
Diese Funktion iteriert durch alle existierende Feuern und berechnet die Temperatur mit gewichtung nach den Abstand.
Falls es keine Feuern gibt ,  dann gibt diese Funktion die Raumtemperatur zurueck.
*/
float maxTemperatur = 0;
float gesamtTemperatur = 0;
float gewichteteTemperatur;

if(sizeof(gruppeFeuer) == 0)
{
    return 20;
}

for(auto& iterator : this->gruppeFeuer){
    
    int abstand = iterator.feuerPosition.vergleichePosition(anderePosition);
    if(abstand == 0){
        gewichteteTemperatur = iterator.Temperatur;
    }
    else{
        gewichteteTemperatur = iterator.Temperatur/(abstand*abstand);
    }

    if(maxTemperatur < gewichteteTemperatur){
        maxTemperatur = gewichteteTemperatur;
    }
    else{
        gesamtTemperatur += gewichteteTemperatur;
    }
    
}

return maxTemperatur + (0.15*gesamtTemperatur)
}