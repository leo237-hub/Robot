//
// Created by irina on 21.04.25.
//
#ifndef APPEND_C_GASSENSOR_H
#define APPEND_C_GASSENSOR_H


class gassensor: {
private:
    std::string gasTyp;
    float grenzwert;

public:
    // Constructor
    GasSensor(const std::string& typ, float grenz);

    // Simulate a gas measurement
    float messwert() const;

    // Check if the gas level is within the safe threshold
    bool istSicher() const;
};

#endif //APPEND_C_GASSENSOR_H