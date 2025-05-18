#include "../include/simulation/feuer.h"
#include <QtMath>
#include <QBrush>

Feuer::Feuer(double x, double y, double radius) {
    setRect(0, 0, radius, radius);
    setBrush(Qt::red);
    setPos(x, y);
}

QPointF Feuer::getCenterPosition() const {
    return scenePos() + rect().center();
}

double Feuer::calculateDistance(const QPointF& other) const {
    return QLineF(getCenterPosition(), other).length();
}

double Feuer::calculateTemperature(double distance) const {
    if (distance == 0.0) return 1000.0;
    return 1000.0 / (distance * distance);
}
