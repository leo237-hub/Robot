#include "test_aktoren.h"

void TestAktoren::testKonstruktor() {
    Aktoren a;
    QVERIFY(true);
}

void TestAktoren::testAnschaltenAusschalten() {
    Aktoren a;
    a.Anschalten();
    a.ausschalten();
    QVERIFY(true);
}

QTEST_APPLESS_MAIN(TestAktoren)
