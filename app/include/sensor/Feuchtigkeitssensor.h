#pragma once

class FeuchtigkeitsSensor {
private:
    float feuchtigkeitNiveau;
    float schwellenwert;  // Optional: could be configurable

public:
    // Constructor
    FeuchtigkeitsSensor(float initialSchwellenwert);
    float feuchtigkeitMessen(float neuerWert);
    bool istUeberSchwellenwert() const;
};


