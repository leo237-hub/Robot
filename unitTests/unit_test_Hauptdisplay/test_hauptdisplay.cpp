#include "test_hauptdisplay.h"

void TestHauptdisplay::testKonstruktor() {
    HauptDisplay h;
    QVERIFY(true);
}

void TestHauptdisplay::testEinschaltenAusschalten() {
    HauptDisplay h;
    h.einschalten();
    QVERIFY(h.istEingeschaltet());
    h.ausschalten();
    QVERIFY(!h.istEingeschaltet());
}

QTEST_APPLESS_MAIN(TestHauptdisplay)
#include "test_hauptdisplay.moc" 