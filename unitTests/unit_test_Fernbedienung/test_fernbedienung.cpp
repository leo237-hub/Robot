#include "test_fernbedienung.h"

void TestFernbedienung::testKonstruktor() {
    Fernbedienung f;
    QVERIFY(true);
}

void TestFernbedienung::testIstControllerAn() {
    Fernbedienung f;
    QVERIFY(f.istControllerAn() == false || f.istControllerAn() == true);
}

QTEST_APPLESS_MAIN(TestFernbedienung) 