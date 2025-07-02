#pragma once
#include <vector>
#include <type_traits>
#include "GpsSensor.h"


template<typename SensorType>
class MittelWerter {
public:
    MittelWerter(const std::vector<SensorType*>& sensoren)
        : sensoren_(sensoren) {}

    float getMittelwert() const {
        if (sensoren_.empty()) return 0.0f;
        float sum = 0.0f;
        for (auto* s : sensoren_) {
            sum += s->getLetzteMessung();
        }
        return sum / sensoren_.size();
    }

    // Spezialisierung für GPSSensor: Mittelwert für X und Y
    template<typename T = SensorType>
    typename std::enable_if<std::is_same<T, GPSSensor>::value, double>::type getMittelwertX() const {
        if (sensoren_.empty()) return 0.0;
        double sum = 0.0;
        for (auto* s : sensoren_) {
            sum += s->getX();
        }
        return sum / sensoren_.size();
    }
    template<typename T = SensorType>
    typename std::enable_if<std::is_same<T, GPSSensor>::value, double>::type getMittelwertY() const {
        if (sensoren_.empty()) return 0.0;
        double sum = 0.0;
        for (auto* s : sensoren_) {
            sum += s->getY();
        }
        return sum / sensoren_.size();
    }

private:
    std::vector<SensorType*> sensoren_;
}; 