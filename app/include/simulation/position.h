#pragma once
#include <QGraphicsEllipseItem>
#include <QtMath>
#include <QBrush>

using namespace  std;

/*
Zweck und Verhalten der Positionsklasse

Zweck: Position tracken und Abstand ergebn
Verhalten: Die Klasse erbt von QGraphicsEllipseItem , somit stehen sehr viele Funktionalitaeten zur Verfuegung
*/

class Position : public QGraphicsEllipseItem {

public:
    Position(double x = 0.0, double y = 0.0, double radius = 10.0);

    QPointF holePosition() const;

    float berechneAbstand(const QPointF& objPosition) const;

    void setzePosition(double x, double y);

    void transformiere(const QTransform& matrix);


private:
    QPointF internePosition;
};

