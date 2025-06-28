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
    void vorwaerts();
    void rueckwaerts();
    void Links();
    void Rechts();
    void stoppen();
public:
    explicit SimRoboter(QObject *parent = nullptr);
    void setRoboter(GraphischesRoboter* rob);
    virtual ~SimRoboter();

public slots:
    void updateSimulation();
};



