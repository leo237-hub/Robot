#include "SimulationRoboter.h"
#include <QGraphicsScene>
#include <QGraphicsView>

SimRoboter::SimRoboter(QObject *parent) : QObject(parent) {}
SimRoboter::~SimRoboter() {}

void SimRoboter::setRoboter(Roboter *rob) {
    roboter = rob;
}

void SimRoboter::vorwaerts() {
    if (!roboter) return;
    roboter->empfangeSignal(signaltyp::Vorvaerts);
    roboter->updateLogic(0.5f);
    refreshView();
}

void SimRoboter::rueckwaerts() {
    if (!roboter) return;
    roboter->empfangeSignal(signaltyp::Rueckwaerts);
    roboter->updateLogic(0.1f);
    refreshView();
}

void SimRoboter::Links() {
    if (!roboter) return;
    roboter->empfangeSignal(signaltyp::Links);
    roboter->updateLogic(0.1f);
    refreshView();
}

void SimRoboter::Rechts() {
    if (!roboter) return;
    roboter->empfangeSignal(signaltyp::Rechts);
    roboter->updateLogic(0.1f);
    refreshView();
}

void SimRoboter::stoppen() {
    if (!roboter) return;
    roboter->empfangeSignal(signaltyp::keine);
    refreshView();
}

void SimRoboter::refreshView() {
    if (!roboter) return;
    roboter->syncGraphics();
    if (roboter->scene()) {
        roboter->scene()->update();
        if (!roboter->scene()->views().isEmpty())
            roboter->scene()->views().first()->viewport()->update();
    }
}
