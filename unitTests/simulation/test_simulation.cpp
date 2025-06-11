#include "test_simulation.h"

void TestSimulation::init()
{
    simulation = new Simulation();
    testScene = new QGraphicsScene();
}

void TestSimulation::cleanup()
{
    delete simulation;
    delete testScene;
}

/*
Test für Konstruktor und Standard Initialisierung
*/
void TestSimulation::testKonstruktor()
{
    QVERIFY(simulation->gruppeFeuer.empty());
    QVERIFY(simulation->Steine.empty());
    QVERIFY(simulation->Personen.empty());
}

/*
Test für Hinzufügen von Feuer zur Umgebung
*/
void TestSimulation::testAddiereFeuerUmgebung()
{
    Feuer* feuer1 = erstelleTestFeuer(10.0, 20.0, 150.0f);
    Feuer* feuer2 = erstelleTestFeuer(30.0, 40.0, 200.0f);
    
    simulation->addiereFeuerUmgebung(feuer1);
    QCOMPARE(simulation->gruppeFeuer.size(), static_cast<size_t>(1));
    QCOMPARE(simulation->gruppeFeuer[0], feuer1);
    
    simulation->addiereFeuerUmgebung(feuer2);
    QCOMPARE(simulation->gruppeFeuer.size(), static_cast<size_t>(2));
    QCOMPARE(simulation->gruppeFeuer[1], feuer2);
}

/*
Test für Hinzufügen von Steinen zur Umgebung
*/
void TestSimulation::testAddiereSteineUmgebung()
{
    simulationElement* stein1 = erstelleTestStein(50.0, 60.0);
    simulationElement* stein2 = erstelleTestStein(70.0, 80.0);
    
    simulation->addiereSteineUmgebung(stein1);
    QCOMPARE(simulation->Steine.size(), static_cast<size_t>(1));
    QCOMPARE(simulation->Steine[0], stein1);
    
    simulation->addiereSteineUmgebung(stein2);
    QCOMPARE(simulation->Steine.size(), static_cast<size_t>(2));
    QCOMPARE(simulation->Steine[1], stein2);
}

/*
Test für Hinzufügen von Personen zur Umgebung
*/
void TestSimulation::testAddierePersonUmgebung()
{
    simulationElement* person1 = erstelleTestPerson(100.0, 110.0);
    simulationElement* person2 = erstelleTestPerson(120.0, 130.0);
    
    simulation->addierePersonUmgebung(person1);
    QCOMPARE(simulation->Personen.size(), static_cast<size_t>(1));
    QCOMPARE(simulation->Personen[0], person1);
    
    simulation->addierePersonUmgebung(person2);
    QCOMPARE(simulation->Personen.size(), static_cast<size_t>(2));
    QCOMPARE(simulation->Personen[1], person2);
}

/*
Test für Temperatur Erzeugung ohne Feuer
*/
void TestSimulation::testErzeugeTemperaturOhneFeuer()
{
    QPointF testPosition(50.0, 50.0);
    
    float temperatur = simulation->erzeugeTemperatur(testPosition);
    
    // Ohne Feuer sollte Temperatur niedrig sein 
    QVERIFY(temperatur >= 0.0f);
    QVERIFY(temperatur <= 25.0f);  // Raumtemperatur oder niedriger
}

/*
Test für Temperatur Erzeugung mit einem Feuer
*/
void TestSimulation::testErzeugeTemperaturMitEinemFeuer()
{
    Feuer* feuer = erstelleTestFeuer(10.0, 10.0, 200.0f);
    simulation->addiereFeuerUmgebung(feuer);
    
    // Position direkt am Feuer
    QPointF feuerPosition(10.0, 10.0);
    float temperaturAmFeuer = simulation->erzeugeTemperatur(feuerPosition);
    QVERIFY(temperaturAmFeuer > 25.0f);
    
    // Position entfernt vom Feuer
    QPointF entferntePosition(50.0, 50.0);
    float temperaturEntfernt = simulation->erzeugeTemperatur(entferntePosition);
    
    // Temperatur sollte mit Entfernung abnehmen
    QVERIFY(temperaturEntfernt < temperaturAmFeuer);
}

/*
Test für Temperatur Erzeugung mit mehreren Feuern
*/
void TestSimulation::testErzeugeTemperaturMitMehrerenFeuern()
{
    Feuer* feuer1 = erstelleTestFeuer(0.0, 0.0, 150.0f);
    Feuer* feuer2 = erstelleTestFeuer(10.0, 0.0, 150.0f);
    
    simulation->addiereFeuerUmgebung(feuer1);
    simulation->addiereFeuerUmgebung(feuer2);
    
    // Position zwischen beiden Feuern
    QPointF mittlerePosition(5.0, 0.0);
    float temperaturMitte = simulation->erzeugeTemperatur(mittlerePosition);
    
    // Position mit nur einem Feuer
    simulation->gruppeFeuer.clear();
    simulation->addiereFeuerUmgebung(feuer1);
    float temperaturEinFeuer = simulation->erzeugeTemperatur(mittlerePosition);
    
    // Mehrere Feuer sollten höhere Temperatur erzeugen
    simulation->addiereFeuerUmgebung(feuer2);
    float temperaturZweiFeuern = simulation->erzeugeTemperatur(mittlerePosition);
    QVERIFY(temperaturZweiFeuern >= temperaturEinFeuer);
}

/*
Test für Temperatur weit entfernt von Feuern
*/
void TestSimulation::testErzeugeTemperaturWeitEntfernt()
{
    Feuer* feuer = erstelleTestFeuer(0.0, 0.0, 300.0f);
    simulation->addiereFeuerUmgebung(feuer);
    
    // Sehr weit entfernte Position
    QPointF weitEntfernt(1000.0, 1000.0);
    float temperatur = simulation->erzeugeTemperatur(weitEntfernt);
    
    // Weit entfernt sollte Temperatur sehr niedrig sein
    QVERIFY(temperatur <= 30.0f);
}

/*
Test für Position Aktualisierung
*/
/*void TestSimulation::testAktualisierePosition()
{
    QPointF neuePosition(100.0, 200.0);
    
    // Methode sollte ohne Fehler ausgeführt werden
    simulation->aktualisierePosition(neuePosition);
    
    QVERIFY(true);
}*/

/*
Test für Scene Integration
*/
void TestSimulation::testAddiereElementeScene()
{
    Feuer* feuer = erstelleTestFeuer(15.0, 25.0);
    simulationElement* stein = erstelleTestStein(35.0, 45.0);
    simulationElement* person = erstelleTestPerson(55.0, 65.0);
    
    simulation->addiereFeuerUmgebung(feuer);
    simulation->addiereSteineUmgebung(stein);
    simulation->addierePersonUmgebung(person);
    
    int anfaenglicheItemAnzahl = testScene->items().size();
    
    simulation->addiereElementeScene(testScene);
    
    // Scene sollte mehr Items haben nach dem Hinzufügen
    QVERIFY(testScene->items().size() >= anfaenglicheItemAnzahl);
}

/*
Test für mehrere Elemente gleichen Typs
*/
void TestSimulation::testMehrereElementeGleichenTyps()
{
    // Mehrere Feuer hinzufügen
    for(int i = 0; i < 5; i++) {
        Feuer* feuer = erstelleTestFeuer(i * 10.0, i * 10.0, 100.0f + i * 20.0f);
        simulation->addiereFeuerUmgebung(feuer);
    }
    
    QCOMPARE(simulation->gruppeFeuer.size(), static_cast<size_t>(5));
    
    // Mehrere Steine hinzufügen
    for(int i = 0; i < 3; i++) {
        simulationElement* stein = erstelleTestStein(i * 15.0, i * 15.0);
        simulation->addiereSteineUmgebung(stein);
    }
    
    QCOMPARE(simulation->Steine.size(), static_cast<size_t>(3));
}

/*
Test für Elemente verschiedener Typen
*/
void TestSimulation::testElementeVerschiedenerTypen()
{
    Feuer* feuer = erstelleTestFeuer(10.0, 10.0);
    simulationElement* stein = erstelleTestStein(20.0, 20.0);
    simulationElement* person = erstelleTestPerson(30.0, 30.0);
    
    simulation->addiereFeuerUmgebung(feuer);
    simulation->addiereSteineUmgebung(stein);
    simulation->addierePersonUmgebung(person);
    
    QCOMPARE(simulation->gruppeFeuer.size(), static_cast<size_t>(1));
    QCOMPARE(simulation->Steine.size(), static_cast<size_t>(1));
    QCOMPARE(simulation->Personen.size(), static_cast<size_t>(1));
    
    // Collections sollten unabhängig voneinander sein
    QVERIFY(simulation->gruppeFeuer[0] != simulation->Steine[0]);
    QVERIFY(simulation->Steine[0] != simulation->Personen[0]);
}

/*
Hilfsmethoden für Test Objekt Erstellung
*/
Feuer* TestSimulation::erstelleTestFeuer(double x, double y, float temperatur)
{
    return new Feuer(x, y, Qt::red, false, 20.0, temperatur);
}

simulationElement* TestSimulation::erstelleTestStein(double x, double y)
{
    return new simulationElement(x, y, Qt::gray, true, 15.0);
}

simulationElement* TestSimulation::erstelleTestPerson(double x, double y)
{
    return new simulationElement(x, y, Qt::blue, false, 12.0);
}

