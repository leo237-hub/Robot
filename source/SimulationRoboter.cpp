#include "SimulationRoboter.h"
#include "roboter.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <cmath>

SimRoboter::~SimRoboter() {}

SimRoboter::SimRoboter(QObject * parent)
    : QObject(parent) {
    connect(&timer, &QTimer::timeout, this, &SimRoboter::update);
}

void SimRoboter::setRoboter(Roboter *rob) {
    roboter = rob;
}

void SimRoboter::startBewegung(float leistung) {
    if(roboter) {
        roboter->vorwaerts(leistung);
        timer.start(16);
    }
}

void SimRoboter::stoppen() {
    if(roboter) {
        roboter->stoppen();
        timer.stop();
    }
}

void SimRoboter::update() {
    if(roboter) {
        float deltaZeit = 0.1f;
        static float zeit = 0.0f;
        static QString letzteBewegung = "";
        zeit += deltaZeit;
        QString aktuelleBewegung;
        if(zeit < 5.0f) {
            aktuelleBewegung = "vorwaerts";
            roboter->vorwaerts(1.0f);
        }
        else if(zeit < 10.0f) {
            aktuelleBewegung = "drehenLinks";
            roboter->drehenLinks(1.0f);
        }
        else if(zeit < 20.0f) {
            aktuelleBewegung = "rueckwaerts";
            roboter->rueckwaerts(1.0f);
        }
        else if(zeit < 30.0f) {
            aktuelleBewegung = "drehenRecht";
            roboter->drehenRechts(1.0f);
        }
        else if(zeit < 40.0f) {
            aktuelleBewegung = "vorwaerts";
            roboter->vorwaerts(1.0f);
        }
        else if(zeit < 50.0f) {
            aktuelleBewegung = "ruckwaerts";
            roboter->rueckwaerts(1.0f);
        }
        else if(zeit < 60.0f) {
            aktuelleBewegung = "drehenRecht";
            roboter->drehenLinks(1.0f);
        }
        else {
            aktuelleBewegung = "stoppen";
            roboter->stoppen();
        }

        if(aktuelleBewegung != letzteBewegung) {
            std::cout << "[Roboter] Zeit: " << static_cast<int>(zeit)
                      << "s | Aktion: " << aktuelleBewegung.toStdString()
                      << " | Position: (" << roboter->getX() << ", " << roboter->getY()
                      << ") | Richtung: " << roboter->getRichtung() << "°" << std::endl;
            // Neue Bewegung merken
            letzteBewegung = aktuelleBewegung;
        }
        if(zeit <= 60.0f) {
            roboter->aktualisierePosition(deltaZeit);
        }
        // Szene und Viewport aktualisieren, damit Bewegung auch auf dem Display sichtbar ist
        if(roboter->scene()) {
            roboter->scene()->update();
            if(!roboter->scene()->views().isEmpty()) {
                roboter->scene()->views().first()->viewport()->update();
            }
        }
    }
}

