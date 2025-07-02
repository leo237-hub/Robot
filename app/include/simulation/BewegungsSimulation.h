#pragma once
#include "BewegungsRoboter.h"
#include <QPointF>

/*
Zweck und Verhalten der BewegungsSimulation-Klasse:

Zweck: Simuliert die Bewegung des Roboters basierend auf dem Zustand der Motoren.
Diese Klasse gehört zur Simulationsumgebung und NICHT zur Robot-Logik.

Verhalten: Liest den Zustand der Motoren vom BewegungsRoboter und berechnet
die neue Position und Ausrichtung des Roboters basierend auf der verstrichenen Zeit.
*/
class BewegungsSimulation {
private:
    BewegungsRoboter* roboter;
    float x, y;
    float winkel;
    
    const float GESCHWINDIGKEITS_MULTIPLIKATOR = 25.0f;

public:
    BewegungsSimulation(BewegungsRoboter* robot);
    
    void aktualisierePosition(float deltazeit);
    
    float getX() const;
    float getY() const;
    float getWinkel() const;
    
   
    void setzePosition(float x, float y, float winkel);
}; 