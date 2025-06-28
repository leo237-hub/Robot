#pragma once
#include <string>

using namespace std;

/*
Zweck und Verhalten der SignalWandler-Klasse:

Zweck: Übersetzung und Weiterleitung von Befehlen zwischen Fernbedienung und Roboterkomponenten.
Fungiert als Kommunikationsschnittstelle zwischen verschiedenen Systemteilen.

Verhalten: Die Klasse empfängt Befehle von der Fernbedienung, interpretiert diese und leitet sie
an die entsprechenden Komponenten weiter. Sie verwaltet auch den Zustand bestimmter Komponenten
(z.B. Paketfach offen/geschlossen, Lampen ein/aus, Audio ein/aus) und sendet Statusinformationen zurück an die Fernbedienung.
*/
class SignalWandler {
private:
    string sensorsignal;
    string fernbedienungsbefehl;
    bool paketfachOffen;
    bool lampenAn;
    bool audioAn;
    
    void behandlePaketfachBefehl();
    void behandleLampenBefehl();
    void behandleAudioBefehl();

public:
    SignalWandler();
    ~SignalWandler() = default;
    
    string EmpfangeBefehlFernBedienung(int gedrucktesKnopf);
    string SendeStatusAnFernBedienung();
    float SendeSensordatenAnFernbedienung();
    
    bool istPaketfachOffen() const;
    bool sindLampenAn() const;
    bool istAudioAn() const;
};