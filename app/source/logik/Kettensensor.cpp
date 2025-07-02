#include "Kettesensor.h"

Kettensensor::Kettensensor(int initialSchritte)
    : AnzahlSchritte(initialSchritte) {}

int Kettensensor::HoleSchritte() const {
    return AnzahlSchritte;
}

void Kettensensor::SchrittHinzufuegen(int schritte) {
    AnzahlSchritte += schritte;
} 