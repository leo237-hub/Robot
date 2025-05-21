#include "../include/simulation/simulation.h"
#include "../include/simulation/position.h"
#include "../include/simulation/feuer.h"
#include "../include/roboter.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <cmath>
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



Simulation::Simulation(QObject* parent)
    : QObject(parent)
{
    connect(&timer, &QTimer::timeout, this, &Simulation::update);
}

void Simulation::setRoboter(Roboter* rob){
    roboter = rob;
}

void Simulation::startBewegung(float leistung){
    if(roboter){
        roboter->vorwaerts(leistung);
        timer.start(16);  // alle 16ms update
    }
}

void Simulation::stoppen(){
    if(roboter){
        roboter->stoppen();
        timer.stop();
    }
}


void Simulation::update(){
    if(roboter){
        // Zeitintervall zwischen Updates (100 ms)
        float deltaZeit = 0.1f;
        // Gesamtzeit seit Start der Simulation
        static float zeit = 0.0f;
        // Merkt sich die zuletzt ausgefuehrte Bewegung
        static QString letzteBewegung = "";
        // Gesamtzeit erhoehen um deltaZeit
        zeit += deltaZeit;

        // Variable fuer aktuelle Bewegung
        QString aktuelleBewegung;
        // Bewegungsphasen abhaengig von der Gesamtzeit (in Sekunden)
        if(zeit < 5.0f){
            // 0-5s vorwaerts fahren
            aktuelleBewegung = "vorwaerts";
            roboter->vorwaerts(1.0f);
        }
        else if(zeit < 10.0f){
            // 5-10s links drehen
            aktuelleBewegung = "drehenLinks";
            roboter->drehenLinks(1.0f);
        }
        else if(zeit < 20.0f){
            // 10-20s rueckwaerts fahren
            aktuelleBewegung = "rueckwaerts";
            roboter->rueckwaerts(1.0f);
        }
        else if(zeit < 30.0f){
            // 20-30s rechts drehen
            aktuelleBewegung = "drehenRechts";
            roboter->drehenRechts(1.0f);
        }
        else if(zeit < 40.0f){
            // 30-40s vorwaerts fahren
            aktuelleBewegung = "vorwaerts";
            roboter->vorwaerts(1.0f);
        }
        else if(zeit < 50.0f){
            // 40-50s rueckwaerts fahren
            aktuelleBewegung = "rueckwaerts";
            roboter->rueckwaerts(1.0f);
        }
        else if(zeit < 55.0f) {
            // 50-55s links drehen
            aktuelleBewegung = "drehenLinks";
            roboter->drehenLinks(1.0f);
        }
        else if(zeit < 60.0f) {
            // 55-60s rechts drehen
            aktuelleBewegung = "drehenRechts";
            roboter->drehenRechts(1.0f);
        }
        else{
            // Nach 60s stoppen
            aktuelleBewegung = "stoppen";
            roboter->stoppen();
        }

        // Ausgabe auf Konsole nur, wenn sich die Bewegung geaendert hat
        if(aktuelleBewegung != letzteBewegung){
            std::cout << "[Roboter] Zeit: " << static_cast<int>(zeit)
            << "s | Aktion: " << aktuelleBewegung.toStdString()
            << " | Position: (" << roboter->getX() << ", " << roboter->getY()
            << ") | Richtung: " << roboter->getRichtung() << "°" << std::endl;
            // Neue Bewegung merken
            letzteBewegung = aktuelleBewegung;
        }

        // Position nur bis 60 Sekunden aktualisieren (danach bleibt Roboter stehen)
        if(zeit <= 60.0f){
            roboter->aktualisierePosition(deltaZeit);
        }

        // Szene und Viewport aktualisieren, damit Bewegung auch auf dem Display sichtbar ist
        if(roboter->scene()){
            roboter->scene()->update();
            if(!roboter->scene()->views().isEmpty()){
                roboter->scene()->views().first()->viewport()->update();
            }
        }
    }
}

