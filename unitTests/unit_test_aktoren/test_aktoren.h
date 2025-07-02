#pragma once
#include <QtTest/QtTest>
#include "aktoren.h"

class TestAktoren : public QObject {
    Q_OBJECT
private slots:
    void testKonstruktor();
    void testAnschaltenAusschalten();
}; 