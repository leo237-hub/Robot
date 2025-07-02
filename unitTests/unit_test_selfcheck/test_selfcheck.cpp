#include "test_selfcheck.h"
#include "TemperaturSensor.h"
#include "Lidarsensor.h"
#include "GpsSensor.h"
#include "Gassensor.h"
#include "Wassersensor.h"
#include "Kettesensor.h"

void TestSelfcheck::testKonstruktor() {
    TemperaturSensor* t[3] = {new TemperaturSensor(), new TemperaturSensor(), new TemperaturSensor()};
    LidarSensor* l[3] = {new LidarSensor(10.0, 5), new LidarSensor(10.0, 5), new LidarSensor(10.0, 5)};
    GPSSensor* g[3] = {new GPSSensor(), new GPSSensor(), new GPSSensor()};
    GasSensor* gas[3] = {new GasSensor(), new GasSensor(), new GasSensor()};
    Wassersensor* w[3] = {new Wassersensor(), new Wassersensor(), new Wassersensor()};
    Kettensensor* k[3] = {new Kettensensor(), new Kettensensor(), new Kettensensor()};
    Selfcheck s(t, l, g, gas, w, k);
    QVERIFY(true);
    for(int i=0;i<3;++i){ delete t[i]; delete l[i]; delete g[i]; delete gas[i]; delete w[i]; delete k[i]; }
}

void TestSelfcheck::testTemperaturSensPruefen() {
    TemperaturSensor* t[3] = {new TemperaturSensor(), new TemperaturSensor(), new TemperaturSensor()};
    LidarSensor* l[3] = {new LidarSensor(10.0, 5), new LidarSensor(10.0, 5), new LidarSensor(10.0, 5)};
    GPSSensor* g[3] = {new GPSSensor(), new GPSSensor(), new GPSSensor()};
    GasSensor* gas[3] = {new GasSensor(), new GasSensor(), new GasSensor()};
    Wassersensor* w[3] = {new Wassersensor(), new Wassersensor(), new Wassersensor()};
    Kettensensor* k[3] = {new Kettensensor(), new Kettensensor(), new Kettensensor()};
    Selfcheck s(t, l, g, gas, w, k);
    QString res = QString::fromStdString(s.TemperaturSensPruefen());
    QVERIFY(!res.isEmpty());
    for(int i=0;i<3;++i){ delete t[i]; delete l[i]; delete g[i]; delete gas[i]; delete w[i]; delete k[i]; }
}

QTEST_APPLESS_MAIN(TestSelfcheck) 