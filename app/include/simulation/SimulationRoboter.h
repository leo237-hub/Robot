#pragma once
#include "GraphischesRoboter.h"
#include <QObject>
#include <QTimer>
using namespace std;

class SimRoboter: public QObject {
    Q_OBJECT
private:
    GraphischesRoboter* roboter = nullptr;
    QTimer* timer;
    bool isActive;
    void refreshView();
private slots:
    void rueckwaerts();

public:
    explicit SimRoboter(QObject *parent = nullptr);
    void setRoboter(GraphischesRoboter* rob);
    virtual ~SimRoboter();
    void Links();
    void vorwaerts();
    void Rechts();
    bool istBlockiert = false;
    bool ausweichenAktiv = false;

public slots:
    void updateSimulation();
    void stoppen();
};



