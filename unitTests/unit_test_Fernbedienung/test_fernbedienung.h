#pragma once
#include <QtTest/QtTest>
#include "Fernbedienung.h"

class TestFernbedienung : public QObject {
    Q_OBJECT
private slots:
    void testKonstruktor();
    void testIstControllerAn();
}; 