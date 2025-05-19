#include "../include/simulation/position.h"

QPointF Position::holePosition() const {
    return scenePos() + rect().center();
}
float Position::berechneAbstand(const QPointF& objPosition){
    return QLineF(holePosition(), objPosition).length();
}
