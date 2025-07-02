#pragma once
#include <QtTest/QtTest>
#include "SignalWandler.h"

class TestSignalWandler : public QObject {
    Q_OBJECT
private slots:
    void testKonstruktor();
    void testEmpfangeBefehlFernBedienung();
}; 