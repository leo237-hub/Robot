#include <QtTest/QtTest>
#include <QCoreApplication>  
#include "simulation/test_position.h"
#include "simulation/test_simulationelement.h"
#include "simulation/test_feuer.h"
#include "simulation/test_xmlhandler.h"
#include "simulation/test_simulation.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);  
    
    int testErgebnisse = 0;
    
    TestPosition positionTest;
    testErgebnisse += QTest::qExec(&positionTest, argc, argv);
    
    TestSimulationElement simulationElementTest;
    testErgebnisse += QTest::qExec(&simulationElementTest, argc, argv);
    
    TestFeuer feuerTest;
    testErgebnisse += QTest::qExec(&feuerTest, argc, argv);
    
    TestXmlHandler xmlHandlerTest;
    testErgebnisse += QTest::qExec(&xmlHandlerTest, argc, argv);
    
    TestSimulation simulationTest;
    testErgebnisse += QTest::qExec(&simulationTest, argc, argv);
    
    return testErgebnisse;
}