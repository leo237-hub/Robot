#include "position.h"

/*
 * Position im Koordinatensystem des Roboters wird als internePosition gespeichert.
 * holePosition() Gibt die aktuelle interne X/Y-Position des Roboters zurück (nicht die GUI-Position).
 * setPos(internePosition); Aktualisiert Position auch grafisch
 * transformiere(): Wendet eine Matrixtransformation (z. B. Rotation, Translation) auf die interne Position an. Für wenn der Roboter rotiert oder verschoben wird.
 */

Position::Position(double x, double y, double radius)
    : QGraphicsEllipseItem(-radius, -radius, 2 * radius, 2 * radius),
    internePosition(x, y)
{
    setBrush(Qt::blue);
    setPos(internePosition);
}

QPointF Position::holePosition() const {
    return internePosition;
}

float Position::berechneAbstand(const QPointF& ziel) const {
    return QLineF(internePosition, ziel).length();
}

void Position::setzePosition(double x, double y) {
    internePosition.setX(x);
    internePosition.setY(y);
    setPos(internePosition);
}

void Position::transformiere(const QTransform& matrix) {
    internePosition = matrix.map(internePosition);
    setPos(internePosition);
}

