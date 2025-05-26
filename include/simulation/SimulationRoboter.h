#pragma once
#include<QObject>
#include<QTimer>
#include<iostream>
#include "../roboter.h"
using namespace std;

class SimRoboter: public QObject {
    Q_OBJECT
private:
    Roboter* roboter = nullptr;
    QTimer timer;
private slots:
    void update();
public:
    explicit SimRoboter(QObject *parent = nullptr);
    void setRoboter(Roboter* rob);
    void startBewegung(float leistung);
    void stoppen();
    virtual ~SimRoboter();
};



