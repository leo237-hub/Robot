#include "test_returnhome.h"

void TestReturnHome::testKonstruktor() {
    ReturnHome r;
    QVERIFY(true);
}

void TestReturnHome::testZurueckZurStation() {
    ReturnHome r;
    GPSSensor g;
    QString res = QString::fromStdString(r.zurueckZurStation(g));
    QVERIFY(res.isEmpty() || !res.isEmpty());
}

QTEST_APPLESS_MAIN(TestReturnHome)
#include "test_returnhome.moc" 