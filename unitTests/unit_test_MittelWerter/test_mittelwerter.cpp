#include "test_mittelwerter.h"
#include <vector>

void TestMittelWerter::testKonstruktor() {
    std::vector<TemperaturSensor*> sensoren;
    MittelWerter<TemperaturSensor> mw(sensoren);
    QVERIFY(true); // Costruttore non crasha
}

void TestMittelWerter::testGetMittelwert() {
    TemperaturSensor t1, t2, t3;
    t1.setLetzteMessung(10.0f);
    t2.setLetzteMessung(20.0f);
    t3.setLetzteMessung(30.0f);
    std::vector<TemperaturSensor*> sensoren = {&t1, &t2, &t3};
    MittelWerter<TemperaturSensor> mw(sensoren);
    QCOMPARE(mw.getMittelwert(), 20.0f);
}

QTEST_APPLESS_MAIN(TestMittelWerter) 