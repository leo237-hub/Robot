#pragma once
#include <QtTest/QtTest>
#include "FernbedienungInterpreter.h"

class TestFernbedienungInterpreter : public QObject {
    Q_OBJECT
private slots:
    void testKonstruktor();
    void testResetAlleKnoepfe();
}; 