#pragma once
#include <array>
#include <cmath>
class GPSSensor {
private:
    double x;
    double y;

public:
    GPSSensor();
    void setPosition(double x, double y);
    double getX() const;
    double getY() const;
};
