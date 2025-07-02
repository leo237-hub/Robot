#pragma once
#include <QtTest/QtTest>
#include "ReturnHome.h"
#include "GpsSensor.h"

class TestReturnHome : public QObject {
    Q_OBJECT
private slots:
    void testKonstruktor();
    void testZurueckZurStation();
}; 