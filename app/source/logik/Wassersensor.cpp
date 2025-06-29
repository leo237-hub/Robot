#include "Wassersensor.h"
#include <thread>
#include <atomic>
#include <chrono>

using namespace std;

Wassersensor::Wassersensor()
    : wasserQuelle([](){ return 30.0f; }), // Standard Luftfeuchtigkeit 30% (abbassato da 50%)
    letzteMessung(30.0f),
    aktiv(false),
    stopFlag(false)
{}

Wassersensor::~Wassersensor() {
    stoppen();
}

void Wassersensor::setWasserQuelle(std::function<float()> quelle) {
    wasserQuelle = quelle;
}

void Wassersensor::starten() {
    if (aktiv) return;
    aktiv = true;
    stopFlag = false;

    messThread = std::thread([this]() { messungLoop(); });
}

void Wassersensor::stoppen() {
    if (!aktiv) return;
    stopFlag = true;
    if (messThread.joinable()) messThread.join();
    aktiv = false;
}

float Wassersensor::getLetzteMessung() const {
    return letzteMessung;
}

void Wassersensor::messungLoop() {
    while(!stopFlag) {
        letzteMessung = wasserQuelle();
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
} 