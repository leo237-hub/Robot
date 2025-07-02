#include "test_fernbedienunginterpreter.h"

void TestFernbedienungInterpreter::testKonstruktor() {
    FernbedienungInterpreter f;
    QVERIFY(true);
}

void TestFernbedienungInterpreter::testResetAlleKnoepfe() {
    FernbedienungInterpreter f;
    f.resetAlleKnoepfe();
    QVERIFY(true);
}

QTEST_APPLESS_MAIN(TestFernbedienungInterpreter) 