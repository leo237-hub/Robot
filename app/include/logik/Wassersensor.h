#pragma once
#include <functional>
#include <thread>
#include <atomic>
using namespace std;

/*
Zweck und Verhalten der Wassersensor-Klasse

Zweck:
Ermöglicht die Erkennung und Messung von Wasser im Roboterumfeld.

Verhalten:
Startet und stoppt Messvorgänge, verwaltet die Quelle der Messdaten und speichert die letzte Messung.
*/

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


