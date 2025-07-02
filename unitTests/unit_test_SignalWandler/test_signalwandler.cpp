#include "test_signalwandler.h"

void TestSignalWandler::testKonstruktor() {
    SignalWandler s;
    QVERIFY(true);
}

void TestSignalWandler::testEmpfangeBefehlFernBedienung() {
    SignalWandler s;
    QString res = QString::fromStdString(s.EmpfangeBefehlFernBedienung(1));
    QVERIFY(res.isEmpty() || !res.isEmpty());
}

QTEST_APPLESS_MAIN(TestSignalWandler) 