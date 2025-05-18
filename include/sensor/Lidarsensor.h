#pragma once
#include <vector>

class LidarSensor {
private:
    float Bereich;       // Maximaler Messbereich in Metern
    float Aufloesung;    // Auflösung in Grad oder Meter

    std::vector<float> scanDaten;  // Gespeicherte Scan-Werte

public:
    // Konstruktor
    LidarSensor(float bereich, float aufloesung);

    // Simuliert einen Umgebungsscan und speichert die Daten
    void UmgebungScannen();

    // Analysiert die gescannten Daten, um Hindernisse zu erkennen
    bool HindernisseErkennen() const;
};

