#pragma once
#include <QtTest/QtTest>
#include "position.h"

/*
Unit Test für Position Klasse
Getestet:
- Konstruktor mit verschiedenen Parametern
- Position setzen und holen
- Abstandsberechnung zwischen Positionen  
- Transformation der Position
- Korrekte Vererbung von QGraphicsEllipseItem
*/

class TestPosition : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void cleanup();
    
    void testKonstruktorStandard();
    void testKonstruktorMitParametern();
    
    void testPositionSetzenUndHolen();
    void testPositionSetzenMitNegativenWerten();
    
    void testAbstandBerechnenZuNullPunkt();
    void testAbstandBerechnenZuAndererPosition();
    void testAbstandBerechnenZuSichSelbst();
    
    void testTransformationMitEinheitsmatrix();
    void testTransformationMitVerschiebung();
    void testTransformationMitSkalierung();
    

private:
    Position* standardPosition;
    Position* testPosition;
};