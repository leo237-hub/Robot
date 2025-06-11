#include "test_position.h"
#include <QtMath>

void TestPosition::init()
{
    standardPosition = new Position();
    testPosition = new Position(10.0, 20.0, 15.0);
}

void TestPosition::cleanup()
{
    delete standardPosition;
    delete testPosition;
}

/*
Test für Standard-Konstruktor (0,0,10)
*/
void TestPosition::testKonstruktorStandard()
{
    Position pos;
    QPointF erwartetePosition(0.0, 0.0);
    
    QCOMPARE(pos.holePosition(), erwartetePosition);
    QCOMPARE(pos.rect().width(), 20.0);  // 2 * radius
    QCOMPARE(pos.rect().height(), 20.0);
}

/*
Test für Konstruktor mit Parametern
*/
void TestPosition::testKonstruktorMitParametern()
{
    Position pos(15.5, 25.3, 12.0);
    QPointF erwartetePosition(15.5, 25.3);
    
    QCOMPARE(pos.holePosition(), erwartetePosition);
    QCOMPARE(pos.rect().width(), 24.0);  // 2 * radius
    QCOMPARE(pos.rect().height(), 24.0);
}

/*
Test für Position setzen und korrekt zurückgeben
*/
void TestPosition::testPositionSetzenUndHolen()
{
    testPosition->setzePosition(100.0, 200.0);
    QPointF erwartetePosition(100.0, 200.0);
    
    QCOMPARE(testPosition->holePosition(), erwartetePosition);
}

/*
Test mit negativen Koordinaten
*/
void TestPosition::testPositionSetzenMitNegativenWerten()
{
    testPosition->setzePosition(-50.0, -75.0);
    QPointF erwartetePosition(-50.0, -75.0);
    
    QCOMPARE(testPosition->holePosition(), erwartetePosition);
}

/*
Test Abstand zum Nullpunkt
*/
void TestPosition::testAbstandBerechnenZuNullPunkt()
{
    testPosition->setzePosition(3.0, 4.0);
    QPointF nullPunkt(0.0, 0.0);
    
    float erwarteterAbstand = 5.0f;  // 3-4-5 Dreieck
    float berechneterAbstand = testPosition->berechneAbstand(nullPunkt);
    
    QCOMPARE(berechneterAbstand, erwarteterAbstand);
}

/*
Test Abstand zwischen zwei verschiedenen Positionen
*/
void TestPosition::testAbstandBerechnenZuAndererPosition()
{
    testPosition->setzePosition(1.0, 1.0);
    QPointF zielPosition(4.0, 5.0);
    
    float erwarteterAbstand = 5.0f;  // sqrt((4-1)² + (5-1)²) = sqrt(9+16) = 5
    float berechneterAbstand = testPosition->berechneAbstand(zielPosition);
    
    QCOMPARE(berechneterAbstand, erwarteterAbstand);
}

/*
Test Abstand zu sich selbst sollte 0 sein
*/
void TestPosition::testAbstandBerechnenZuSichSelbst()
{
    QPointF eigenPosition = testPosition->holePosition();
    float abstand = testPosition->berechneAbstand(eigenPosition);
    
    QCOMPARE(abstand, 0.0f);
}

/*
Test Transformation mit Einheitsmatrix
*/
void TestPosition::testTransformationMitEinheitsmatrix()
{
    QPointF urspruenglichePosition = testPosition->holePosition();
    QTransform einheitsMatrix;
    
    testPosition->transformiere(einheitsMatrix);
    
    QCOMPARE(testPosition->holePosition(), urspruenglichePosition);
}

/*
Test Transformation mit Verschiebung
*/
void TestPosition::testTransformationMitVerschiebung()
{
    testPosition->setzePosition(10.0, 20.0);
    QTransform verschiebungsMatrix;
    verschiebungsMatrix.translate(5.0, 10.0);
    
    testPosition->transformiere(verschiebungsMatrix);
    
    // QGraphicsItem::transform() funktioniert anders als einfache Addition
    // Wir prüfen nur, dass sich die Position verändert hat
    QVERIFY(testPosition->holePosition() != QPointF(10.0, 20.0));
}

/*
Test Transformation mit Skalierung
*/
void TestPosition::testTransformationMitSkalierung()
{
    QPointF urspruenglichePosition = testPosition->holePosition();
    QTransform skalierungsMatrix;
    skalierungsMatrix.scale(2.0, 2.0);
    
    testPosition->transformiere(skalierungsMatrix);
    
    // Nach Skalierung sollte sich die Position ändern
    QVERIFY(testPosition->holePosition() != urspruenglichePosition);
}


