#include "GpsSensor.h"

GPSSensor::GPSSensor() : x(0.0), y(0.0) {}

void GPSSensor::setPosition(double newX, double newY) {
    x = newX;
    y = newY;
}

double GPSSensor::getX() const {
    return x;
}

double GPSSensor::getY() const {
    return y;
}
