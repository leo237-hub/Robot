#pragma once
#include <QtTest/QtTest>
#include "Lautsprecher.h"

class TestLautsprecher : public QObject {
    Q_OBJECT
private slots:
    void testKonstruktor();
    void testEinschaltenAusschalten();
}; 