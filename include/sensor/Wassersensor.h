#pragma once

class Wassersensor {
private:
    float WasserStand;
    float schwellenwert;

public:
    Wassersensor(float initialSchwellenwert);
    float wasserstandMessen(float neuerStand);
    bool istUntergetaucht() const;
};


