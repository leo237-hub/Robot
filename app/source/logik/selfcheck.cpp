#include<string>
#include<iostream>
#include "selfcheck.h"

using namespace  std;



Selfcheck::Selfcheck(TemperaturSensor* t[3], LidarSensor* l[3], GPSSensor* g[3], GasSensor* gas[3], Wassersensor* w[3], Kettensensor* k[3]) {
    for (int i = 0; i < 3; ++i) {
        tempSensor[i] = t[i];
        lidarSensor[i] = l[i];
        gpsSensor[i] = g[i];
        gasSensor[i] = gas[i];
        wasserSensor[i] = w[i];
        ketteSensor[i] = k[i];
    }
}

Selfcheck::~Selfcheck() {}

std::string Selfcheck::TemperaturSensPruefen() {
    float v[3];
    for (int i = 0; i < 3; ++i) {
        v[i] = tempSensor[i]->getLetzteMessung();
    }
    float maxV = std::max({v[0], v[1], v[2]});
    float minV = std::min({v[0], v[1], v[2]});
    if ((maxV - minV) > maxAbweichung) {
        return "Fehler: TemperaturSensor Abweichung zu groß";
    }
    return "OK";
}

std::string Selfcheck::GassensorPruefen() {
    float v[3];
    for (int i = 0; i < 3; ++i) {
        v[i] = gasSensor[i]->getLetzteMessung();
    }
    float maxV = std::max({v[0], v[1], v[2]});
    float minV = std::min({v[0], v[1], v[2]});
    if ((maxV - minV) > maxAbweichung) {
        return "Fehler: Gassensor Abweichung zu groß";
    }
    return "OK";
}

std::string Selfcheck::WasserSensPruefen() {
    float v[3];
    for (int i = 0; i < 3; ++i) {
        v[i] = wasserSensor[i]->getLetzteMessung();
    }
    float maxV = std::max({v[0], v[1], v[2]});
    float minV = std::min({v[0], v[1], v[2]});
    if ((maxV - minV) > maxAbweichung) {
        return "Fehler: Wassersensor Abweichung zu groß";
    }
    return "OK";
}

std::string Selfcheck::LidarSensorPruefen() {
    double v[3];
    for (int i = 0; i < 3; ++i) {
        const std::vector<double>& d = lidarSensor[i]->gibDistanzen();
        v[i] = d.empty() ? 0.0 : d[0];
    }
    double maxV = std::max({v[0], v[1], v[2]});
    double minV = std::min({v[0], v[1], v[2]});
    if ((maxV - minV) > maxAbweichung) {
        return "Fehler: LidarSensor Abweichung zu groß";
    }
    return "OK";
}

std::string Selfcheck::GPsSensorPruefen() {
    double x[3], y[3];
    for (int i = 0; i < 3; ++i) {
        x[i] = gpsSensor[i]->getX();
        y[i] = gpsSensor[i]->getY();
    }
    double maxX = std::max({x[0], x[1], x[2]});
    double minX = std::min({x[0], x[1], x[2]});
    double maxY = std::max({y[0], y[1], y[2]});
    double minY = std::min({y[0], y[1], y[2]});
    if ((maxX - minX) > maxAbweichung || (maxY - minY) > maxAbweichung) {
        return "Fehler: GPSSensor Abweichung zu groß";
    }
    return "OK";
}

std::string Selfcheck::KetteSensPruefen() {
    int v[3];
    for (int i = 0; i < 3; ++i) {
        v[i] = ketteSensor[i]->HoleSchritte();
    }
    int maxV = std::max({v[0], v[1], v[2]});
    int minV = std::min({v[0], v[1], v[2]});
    if ((maxV - minV) > static_cast<int>(maxAbweichung)) {
        return "Fehler: Kettensensor Abweichung zu groß";
    }
    return "OK";
}
