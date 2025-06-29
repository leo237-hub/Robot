#pragma once
#include <functional>
#include <thread>
#include <atomic>
using namespace std;

class Wassersensor {
public:
    Wassersensor();
    ~Wassersensor();

    void setWasserQuelle(std::function<float()> quelle);
    void starten();
    void stoppen();
    float getLetzteMessung() const;

private:
    function<float()> wasserQuelle;
    float letzteMessung;

    bool aktiv;
    // Zum Timer-Ersatz
    thread messThread;
    atomic<bool> stopFlag;

    void messungLoop();
};


