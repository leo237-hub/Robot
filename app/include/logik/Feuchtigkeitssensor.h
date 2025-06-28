#pragma once

class FeuchtigkeitsSensor {
private:
    float feuchtigkeitNiveau;
    float schwellenwert;  

public:
    
    FeuchtigkeitsSensor(float initialSchwellenwert);
    float feuchtigkeitMessen(float neuerWert);
    bool istUeberSchwellenwert() const;
};


