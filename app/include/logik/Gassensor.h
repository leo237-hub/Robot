#pragma once
#include <functional>
#include <thread>
#include <atomic>
#include <string>
using namespace std;

class GasSensor {
public:
    GasSensor();
    ~GasSensor();

    void setGasQuelle(std::function<float()> quelle);
    void starten();
    void stoppen();
    float getLetzteMessung() const;
    float getGrenzwert() const;
    void setzeGrenzwert(float grenzwert);

private:
    function<float()> gasQuelle;
    float letzteMessung;
    float grenzwert;
    bool aktiv;
    
    // Zum Timer-Ersatz
    thread messThread;
    atomic<bool> stopFlag;

    void messungLoop();
};
