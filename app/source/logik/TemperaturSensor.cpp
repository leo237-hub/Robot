#include "TemperaturSensor.h"
#include <thread>
#include <atomic>
#include <chrono>

using namespace std;

TemperaturSensor::TemperaturSensor()
    : temperaturQuelle([](){ return 20.0f; }),
    letzteMessung(20.0f),
    aktiv(false),
    stopFlag(false)
{}

TemperaturSensor::~TemperaturSensor() {
    stoppen();
}

void TemperaturSensor::setTemperaturQuelle(std::function<float()> quelle) {
    temperaturQuelle = quelle;
}

void TemperaturSensor::starten() {
    if (aktiv) return;
    aktiv = true;
    stopFlag = false;

    messThread = std::thread([this]() { messungLoop(); });
}

void TemperaturSensor::stoppen() {
    if (!aktiv) return;
    stopFlag = true;
    if (messThread.joinable()) messThread.join();
    aktiv = false;
}

float TemperaturSensor::getLetzteMessung() const {
    return letzteMessung;
}

void TemperaturSensor::messungLoop() {
    while(!stopFlag) {
        float nuovaTemp = temperaturQuelle();
        letzteMessung = nuovaTemp;
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}
