#pragma once


class GasSensor {
private:
    std::string gasTyp;
    float grenzwert;

public:
    GasSensor(const std::string& typ, float grenz);
    float messwert() const;
    bool istSicher() const;
};
