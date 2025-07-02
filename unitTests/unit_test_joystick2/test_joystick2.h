#pragma once
#include <QtTest/QtTest>
#include "joystick2.h"

class TestJoystick2 : public QObject {
    Q_OBJECT
private slots:
    void testKonstruktor();
    void testSetGetWinkel();
}; 