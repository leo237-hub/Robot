#pragma once
#include <QtTest/QtTest>
#include "MittelWerter.h"
#include "TemperaturSensor.h"

class TestMittelWerter : public QObject {
    Q_OBJECT
private slots:
    void testKonstruktor();
    void testGetMittelwert();
}; 