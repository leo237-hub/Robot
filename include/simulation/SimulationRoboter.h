#pragma once
#include <QObject>
#include "roboter.h"
using namespace std;

class SimRoboter: public QObject {
    Q_OBJECT
private:
    Roboter* roboter = nullptr;
    void refreshView();
private slots:
    void vorwaerts();
    void rueckwaerts();
    void Links();
    void Rechts();
    void stoppen();
public:
    explicit SimRoboter(QObject *parent = nullptr);
    void setRoboter(Roboter* rob);
   virtual ~SimRoboter();
};



