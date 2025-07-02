#pragma once
#include <QtTest/QtTest>
#include "selfcheck.h"

class TestSelfcheck : public QObject {
    Q_OBJECT
private slots:
    void testKonstruktor();
    void testTemperaturSensPruefen();
}; 