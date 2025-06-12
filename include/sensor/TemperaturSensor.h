#pragma once
#include <functional>
#include <thread>
#include <atomic>

using namespace std;

class TemperaturSensor {
public:
    TemperaturSensor();
    ~TemperaturSensor();

    void setTemperaturQuelle(std::function<float()> quelle);
    void starten();
    void stoppen();
    float getLetzteMessung() const;

private:
    function<float()> temperaturQuelle;
    float letzteMessung;

    bool aktiv;
    // Zum Timer-Ersatz
    thread messThread;
    atomic<bool> stopFlag;

    void messungLoop();
};
