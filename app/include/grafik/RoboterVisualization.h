#pragma once
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include "BewegungsRoboter.h"
#include "BewegungsSimulation.h"

/*
Zweck und Verhalten der RoboterVisualization-Klasse:

Zweck: Grafische Darstellung und Simulation des Roboters für Entwicklungs- und Testzwecke.
Diese Klasse wird NUR für die Simulation verwendet und läuft NICHT auf der echten Hardware.

Verhalten: Zeigt den Roboter grafisch an, simuliert Benutzereingaben und visualisiert
den Zustand des Roboters. Kommuniziert mit BewegungsRoboter für die eigentliche Logik.
*/
class RoboterVisualization : public QGraphicsEllipseItem {

private:
    BewegungsRoboter* bewegungsRoboter;
    BewegungsSimulation* bewegungsSimulation;
    bool isSimulationActive;

public:
    RoboterVisualization(BewegungsRoboter* bewegung, double x = 0.0, double y = 0.0, double radius = 20.0);
    ~RoboterVisualization();
    
    // Visualization methods only
    void updateVisualization();
    void setSimulationActive(bool active);
    bool getSimulationActive() const;
    
    // Input simulation (for testing)
    void simulateKeyPress(const QString& key);
    void simulateSignal(signaltyp signal);

protected:
    void keyPressEvent(QKeyEvent *event) override;
}; 