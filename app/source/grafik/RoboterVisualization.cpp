#include "RoboterVisualization.h"
#include <QBrush>
#include <QRadialGradient>
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsScene>
#include "Dc-SignalInterpreter.h"
#include "BewegungsSimulation.h"

RoboterVisualization::RoboterVisualization(BewegungsRoboter* bewegung, double x, double y, double radius)
    : bewegungsRoboter(bewegung), simulationIstAktiv(true) {
    
    /* BewegungsSimulation erstellen */
    bewegungsSimulation = new BewegungsSimulation(bewegung);
    bewegungsSimulation->setzePosition(x, y, 0.0f);
    
    setRect(0, 0, radius, radius);
    
    /* Visuelles Erscheinungsbild erstellen */
    QRadialGradient gradient(radius * 0.8, radius/2, radius * 0.3); 
    gradient.setColorAt(0, Qt::red);       
    gradient.setColorAt(0.5, Qt::blue);    
    gradient.setColorAt(1, Qt::blue);       
    
    setBrush(gradient);
    setTransformOriginPoint(rect().center());
    setPos(x, y);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    qDebug() << "[RoboterVisualization] Focusable:" << flags().testFlag(QGraphicsItem::ItemIsFocusable) << "Has focus:" << hasFocus();
}

RoboterVisualization::~RoboterVisualization() {
    if (bewegungsSimulation) {
        delete bewegungsSimulation;
    }
}

void RoboterVisualization::visualisierungAktualisieren() {
    if (!bewegungsRoboter || !bewegungsSimulation || !simulationIstAktiv) return;
    
    /* Visuelle Position basierend auf Simulationsposition aktualisieren */
    float x = bewegungsSimulation->getX();
    float y = bewegungsSimulation->getY();
    float direction = bewegungsSimulation->getWinkel();
    
    setPos(x, y);
    setRotation(direction);
    
    /* Szene aktualisieren falls verfügbar */
    if (scene()) {
        scene()->update();
    }
}

void RoboterVisualization::simulationAktivSetzen(bool active) {
    simulationIstAktiv = active;
}

bool RoboterVisualization::istSimulationAktiv() const {
    return simulationIstAktiv;
}

void RoboterVisualization::tastaturDruckSimulieren(const QString& key) {
    if (!bewegungsRoboter || !bewegungsSimulation || !simulationIstAktiv) return;
    
    Dc_SignalInterpreter interpreter;
    signaltyp signal;
    
    if (key == "w" || key == "W") {
        signal = interpreter.EingabeInterpretieren("w");
    } else if (key == "a" || key == "A") {
        signal = interpreter.EingabeInterpretieren("a");
    } else if (key == "s" || key == "S") {
        signal = interpreter.EingabeInterpretieren("s");
    } else if (key == "d" || key == "D") {
        signal = interpreter.EingabeInterpretieren("d");
    } else {
        qDebug() << "Unbekannte Taste:" << key;
        return;
    }
    
    bewegungsRoboter->EmpfangeJoystick1(signal);
    bewegungsSimulation->aktualisierePosition(0.05f);
    visualisierungAktualisieren();
}

void RoboterVisualization::signalSimulieren(signaltyp signal) {
    if (!bewegungsRoboter || !bewegungsSimulation || !simulationIstAktiv) return;
    
    bewegungsRoboter->EmpfangeJoystick1(signal);
    bewegungsSimulation->aktualisierePosition(0.05f);
    visualisierungAktualisieren();
}

void RoboterVisualization::keyPressEvent(QKeyEvent *event) {
    qDebug() << "[RoboterVisualization] keyPressEvent received, key:" << event->key() << "Has focus:" << hasFocus();
    if (!simulationIstAktiv) {
        event->ignore();
        return;
    }

    // Gestione frecce sinistra/destra SOLO per la testa
    if (event->key() == Qt::Key_Left) {
        if (bewegungsRoboter)
            bewegungsRoboter->EmpfangeJoystick2(signaltyp::DrehenLinks);
        event->accept();
        return;
    } else if (event->key() == Qt::Key_Right) {
        if (bewegungsRoboter)
            bewegungsRoboter->EmpfangeJoystick2(signaltyp::DrehenRechts);
        event->accept();
        return;
    }

    // Gestione WASD e frecce su/giù SOLO per il movimento
    QString key;
    switch(event->key()) {
    case Qt::Key_W:
        key = "w";
        break;
    case Qt::Key_A:
        key = "a";
        break;
    case Qt::Key_S:
        key = "s";
        break;
    case Qt::Key_D:
        key = "d";
        break;
    case Qt::Key_Up:
        key = "w";
        break;
    case Qt::Key_Down:
        key = "s";
        break;
    case Qt::Key_Q:
        qDebug() << "Simulation beendet.";
        event->accept();
        return;
    default:
        qDebug() << "Unbekannte Taste gedrückt.";
        event->ignore();
        return;
    }
    tastaturDruckSimulieren(key);
    event->accept();
}

void RoboterVisualization::keyReleaseEvent(QKeyEvent *event) {
    if (!simulationIstAktiv) {
        event->ignore();
        return;
    }
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_Right) {
        if (bewegungsRoboter)
            bewegungsRoboter->EmpfangeJoystick2(signaltyp::keine);
        event->accept();
        return;
    }
    if (event->key() == Qt::Key_W || event->key() == Qt::Key_A || event->key() == Qt::Key_S || event->key() == Qt::Key_D ||
        event->key() == Qt::Key_Up || event->key() == Qt::Key_Down) {
        if (bewegungsRoboter)
            bewegungsRoboter->EmpfangeJoystick1(signaltyp::keine);
        event->accept();
        return;
    }
    event->ignore();
} 