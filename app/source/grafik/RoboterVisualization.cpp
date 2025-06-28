#include "RoboterVisualization.h"
#include <QBrush>
#include <QRadialGradient>
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsScene>
#include "Dc-SignalInterpreter.h"
#include "BewegungsSimulation.h"

RoboterVisualization::RoboterVisualization(BewegungsRoboter* bewegung, double x, double y, double radius)
    : bewegungsRoboter(bewegung), isSimulationActive(true) {
    
    // Create BewegungsSimulation
    bewegungsSimulation = new BewegungsSimulation(bewegung);
    bewegungsSimulation->setzePosition(x, y, 0.0f);
    
    setRect(0, 0, radius, radius);
    
    // Create visual appearance
    QRadialGradient gradient(radius * 0.8, radius/2, radius * 0.3); 
    gradient.setColorAt(0, Qt::red);       
    gradient.setColorAt(0.5, Qt::blue);    
    gradient.setColorAt(1, Qt::blue);       
    
    setBrush(gradient);
    setTransformOriginPoint(rect().center());
    setPos(x, y);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

RoboterVisualization::~RoboterVisualization() {
    if (bewegungsSimulation) {
        delete bewegungsSimulation;
    }
}

void RoboterVisualization::updateVisualization() {
    if (!bewegungsRoboter || !bewegungsSimulation || !isSimulationActive) return;
    
    // Update visual position based on simulation position
    float x = bewegungsSimulation->getX();
    float y = bewegungsSimulation->getY();
    float direction = bewegungsSimulation->getWinkel();
    
    setPos(x, y);
    setRotation(direction);
    
    // Update scene if available
    if (scene()) {
        scene()->update();
    }
}

void RoboterVisualization::setSimulationActive(bool active) {
    isSimulationActive = active;
}

bool RoboterVisualization::getSimulationActive() const {
    return isSimulationActive;
}

void RoboterVisualization::simulateKeyPress(const QString& key) {
    if (!bewegungsRoboter || !bewegungsSimulation || !isSimulationActive) return;
    
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
        qDebug() << "Unknown key:" << key;
        return;
    }
    
    bewegungsRoboter->Empfangesignal(signal);
    bewegungsSimulation->aktualisierePosition(0.05f);
    updateVisualization();
}

void RoboterVisualization::simulateSignal(signaltyp signal) {
    if (!bewegungsRoboter || !bewegungsSimulation || !isSimulationActive) return;
    
    bewegungsRoboter->Empfangesignal(signal);
    bewegungsSimulation->aktualisierePosition(0.05f);
    updateVisualization();
}

void RoboterVisualization::keyPressEvent(QKeyEvent *event) {
    if (!isSimulationActive) {
        event->ignore();
        return;
    }
    
    QString key;
    switch(event->key()) {
    case Qt::Key_W:
    case Qt::Key_Up:
        key = "w";
        break;
    case Qt::Key_A:
    case Qt::Key_Left:
        key = "a";
        break;
    case Qt::Key_S:
    case Qt::Key_Down:
        key = "s";
        break;
    case Qt::Key_D:
    case Qt::Key_Right:
        key = "d";
        break;
    case Qt::Key_Q:
        qDebug() << "Simulation ended.";
        event->accept();
        return;
    default:
        qDebug() << "Unknown key pressed.";
        event->ignore();
        return;
    }
    
    simulateKeyPress(key);
    event->accept();
} 