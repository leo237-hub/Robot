#pragma once
#include <functional>
#include <thread>
#include <atomic>
using namespace std;

/*
Zweck und Verhalten der TemperaturSensor-Klasse

Zweck:
Ermöglicht die Erfassung und Messung der Umgebungstemperatur im Roboter.

Verhalten:
Startet und stoppt Messvorgänge, verwaltet die Quelle der Temperaturdaten und speichert die letzte Messung.
*/

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
