//
// Created by irina on 21.04.25.
//
#ifndef APPEND_C_GASSENSOR_H
#define APPEND_C_GASSENSOR_H

#endif //APPEND_C_GASSENSOR_H

class gassensor: {
private:
    std::string gasTyp;
    float grenzwert;
public:
    // Constructor
    GasSensor(const std::string& typ, float grenz) : gasTyp(typ), grenzwert(grenz) {
    }

    // Simulate a gas measurement (just returns a random float for demo)
    float messwert() const {
    }
    // Check if the current gas level is safe
    bool istSicher() const {
        float wert = messwert();
        std::cout << "Gemessener Wert für " << gasTyp << ": " << wert << std::endl;
        return wert <= grenzwert;
    }
};