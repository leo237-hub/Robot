#pragma once
#include <string>

class Sensor {
public:
    virtual ~Sensor() = default;
    virtual float messen() = 0;
    virtual void kalibrieren() = 0;
    virtual std::string getID() const = 0;
    virtual std::string getTyp() const = 0;
    virtual std::string getEinheit() const = 0;
}; 