#pragma once
#include <QtTest/QtTest>
#include <QGraphicsScene>
#include "simulation.h"
#include "feuer.h"

/*
Unit Test für Simulation Klasse
Getestet:
- Konstruktor und Initialisierung
- Hinzufügen von Feuer Elementen
- Hinzufügen von Stein Elementen  
- Hinzufügen von Person Elementen
- Temperatur Erzeugung basierend auf Position
- Position Aktualisierung
- Scene Integration
- Verwaltung verschiedener Element Collections
*/

class TestSimulation : public QObject
{
    Q_OBJECT
    

private slots:
    void init();
    void cleanup();
    
    void testKonstruktor();
    void testAddiereFeuerUmgebung();
    void testAddiereSteineUmgebung();
    void testAddierePersonUmgebung();
    
    void testErzeugeTemperaturOhneFeuer();
    void testErzeugeTemperaturMitEinemFeuer();
    void testErzeugeTemperaturMitMehrerenFeuern();
    void testErzeugeTemperaturWeitEntfernt();
    
    //void testAktualisierePosition();
    void testAddiereElementeScene();
    
    void testMehrereElementeGleichenTyps();
    void testElementeVerschiedenerTypen();

private:
    Simulation* simulation;
    QGraphicsScene* testScene;
    
    Feuer* erstelleTestFeuer(double x, double y, float temperatur = 100.0f);
    simulationElement* erstelleTestStein(double x, double y);
    simulationElement* erstelleTestPerson(double x, double y);
};