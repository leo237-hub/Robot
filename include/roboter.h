#ifndef ROBOTER_H
#define ROBOTER_H

/*
class roboter {
    float leistung;
    int richt;
public:
    roboter();
};
*/

#include <QGraphicsEllipseItem>

class Roboter : public QGraphicsEllipseItem {
public:
    Roboter(double x, double y, double radius = 20.0);

    QPointF getCenterPosition() const;
};

#endif // ROBOTER_H
