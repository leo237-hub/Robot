#include "test_lautsprecher.h"

void TestLautsprecher::testKonstruktor() {
    Lautsprecher l;
    QVERIFY(true);
}

void TestLautsprecher::testEinschaltenAusschalten() {
    Lautsprecher l;
    l.einschalten();
    QVERIFY(l.istEingeschaltet());
    l.ausschalten();
    QVERIFY(!l.istEingeschaltet());
}

QTEST_APPLESS_MAIN(TestLautsprecher) 