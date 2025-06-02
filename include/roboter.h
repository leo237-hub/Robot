#pragma once
#include <QGraphicsEllipseItem>
#include <string>
#include "dcmotor.h"
#include "BewegungsRoboter.h"

class Roboter : public QGraphicsEllipseItem {
private:
    BewegungsRoboter bewegungslogik;
    dcMotor motorLinks;
    dcMotor motorRechts;
    float x;
    float y;
    float winkel;

public:
    Roboter(double x = 0.0, double y = 0.0, double radius = 20.0);
    ~Roboter();

    void vorwaerts(float leistung);
    void rueckwaerts(float leistung);
    void drehenLinks(float leistung);
    void drehenRechts(float leistung);
    void stoppen();
    void aktualisierePosition(float deltaZeit);
    void bewegungtesten();
    void statusausgeben();

    // basiert auf QGraphicsItem::pos()
    float getX() const;
    float getY() const;
    float getRichtung() const;

    QPointF getCenterPosition() const;
};




/*
#ifndef ROBOTER_H
#define ROBOTER_H


class roboter {
    float leistung;
    int richt;
public:
    roboter();
};
*/
/*
#include <QGraphicsEllipseItem>

class Roboter : public QGraphicsEllipseItem {
public:
    Roboter(double x, double y, double radius = 20.0);

    QPointF getCenterPosition() const;
};


#endif // ROBOTER_H

*/
