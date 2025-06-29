#include "Gassensor.h"
#include <thread>
#include <atomic>
#include <chrono>
#include <random>

using namespace std;

GasSensor::GasSensor()
    : gasQuelle([](){ 
        // Simuliere zufällige Gaswerte zwischen 0% und 100%
        static random_device rd;
        static mt19937 gen(rd());
        static uniform_real_distribution<float> dis(0.0f, 100.0f);
        return dis(gen);
    }),
    letzteMessung(0.0f),
    grenzwert(50.0f), // Standard-Grenzwert bei 50%
    aktiv(false),
    stopFlag(false)
{}

GasSensor::~GasSensor() {
    stoppen();
}

void GasSensor::setGasQuelle(std::function<float()> quelle) {
    gasQuelle = quelle;
}

void GasSensor::starten() {
    if (aktiv) return;
    aktiv = true;
    stopFlag = false;

    messThread = std::thread([this]() { messungLoop(); });
}

void GasSensor::stoppen() {
    if (!aktiv) return;
    stopFlag = true;
    if (messThread.joinable()) messThread.join();
    aktiv = false;
}

float GasSensor::getLetzteMessung() const {
    return letzteMessung;
}

float GasSensor::getGrenzwert() const {
    return grenzwert;
}

void GasSensor::setzeGrenzwert(float neuerGrenzwert) {
    grenzwert = neuerGrenzwert;
}

void GasSensor::messungLoop() {
    while(!stopFlag) {
        letzteMessung = gasQuelle();
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Alle 100ms messen
    }
} 