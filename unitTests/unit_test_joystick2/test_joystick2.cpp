#include "test_joystick2.h"

void TestJoystick2::testKonstruktor() {
    joystick2 j;
    QVERIFY(true);
}

void TestJoystick2::testSetGetWinkel() {
    joystick2 j;
    j.setzeWinkel(45.0f);
    QCOMPARE(j.getWinkel(), 45.0f);
}

QTEST_APPLESS_MAIN(TestJoystick2)
