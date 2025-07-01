#include "SimulationRoboter.h"
#include "GraphischesRoboter.h"
#include <QGraphicsScene>
#include <QGraphicsView>

SimRoboter::SimRoboter(QObject *parent) : QObject(parent) {}
SimRoboter::~SimRoboter() {}

void SimRoboter::setRoboter(GraphischesRoboter *rob) {
    roboter = rob;
}

void SimRoboter::vorwaerts() {
       if (!roboter) return;
        if (istBlockiert) {
            stoppen();
            return;
        }
    roboter->empfangesignal(signaltyp::Vorvaerts);
    roboter->logikAktualisieren(0.05f);
    refreshView();
}

void SimRoboter::rueckwaerts() {
    if (!roboter) return;
    roboter->empfangesignal(signaltyp::Rueckwaerts);
    roboter->logikAktualisieren(0.05f);
    refreshView();
}

void SimRoboter::Links() {
    if (!roboter) return;
    roboter->empfangesignal(signaltyp::Links);
    roboter->logikAktualisieren(0.05f);
    refreshView();
}

void SimRoboter::Rechts() {
    if (!roboter) return;
    roboter->empfangesignal(signaltyp::Rechts);
    roboter->logikAktualisieren(0.05f);
    refreshView();
}

void SimRoboter::stoppen() {
    if (!roboter) return;
    roboter->empfangesignal(signaltyp::keine);
    roboter->logikAktualisieren(0.05f);
    refreshView();
}

void SimRoboter::updateSimulation() {
    if (!roboter) return;
    roboter->logikAktualisieren(0.05f);
    refreshView();
}

void SimRoboter::refreshView() {
    if (!roboter) return;
    roboter->grafikSynchronisieren();
    if (roboter->scene()) {
        roboter->scene()->update();
        if (!roboter->scene()->views().isEmpty())
            roboter->scene()->views().first()->viewport()->update();
    }
}
