#pragma once
#include <QtTest/QtTest>
#include "Hauptdisplay.h"

class TestHauptdisplay : public QObject {
    Q_OBJECT
private slots:
    void testKonstruktor();
    void testEinschaltenAusschalten();
}; 