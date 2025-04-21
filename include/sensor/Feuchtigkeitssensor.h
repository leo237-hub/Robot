#ifndef APPEND_C_FEUCHTIGKEITSSENSOR_H
#define APPEND_C_FEUCHTIGKEITSSENSOR_H

class FeuchtigkeitsSensor {
private:
    float feuchtigkeitNiveau;
    float schwellenwert;  // Optional: could be configurable

public:
    // Constructor
    FeuchtigkeitsSensor(float initialSchwellenwert);

    // Measure humidity (simulated or updated externally)
    float feuchtigkeitMessen(float neuerWert);

    // Check if the current humidity is over the threshold
    bool istUeberSchwellenwert() const;
};

#endif //APPEND_C_FEUCHTIGKEITSSENSOR_H
