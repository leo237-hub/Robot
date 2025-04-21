#ifndef APPEND_C_WASSERSENSOR_H
#define APPEND_C_WASSERSENSOR_H

class Wassersensor {
private:
    float WasserStand;
    float schwellenwert;  // Threshold to define "untergetaucht"

public:
    // Constructor
    Wassersensor(float initialSchwellenwert);

    // Sets and returns the current water level
    float wasserstandMessen(float neuerStand);

    // Returns true if the sensor is submerged
    bool istUntergetaucht() const;
};

#endif //APPEND_C_WASSERSENSOR_H
