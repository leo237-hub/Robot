#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "include/simulation/simulation.h"
#include <QRandomGenerator>
#include <QGraphicsView>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*
    TODO: Instanziierung von folgenden Klassen
    1. TemperaturSensor
    2. Simulationsklasse
    3. Bewegung (Amer schreibe hier ganeu was du dier einfallen lassen hast)
    4. Display
    5. Joystick
    */
    
/*
 * mahle rote punkt als feuer und blaue als roboter
 *
 */
    Simulation  * simulation = new Simulation();
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0, 0, 400, 300);

    roboter = new Roboter(50, 100);
    scene->addItem(roboter);
    for(int i = 0; i < 5;i++){

    feuer = new Feuer(QRandomGenerator::global()->bounded(0, 500), QRandomGenerator::global()->bounded(0, 200)); // Zufaellige Zahlen fuer die Position um verschiedene Umgebungen zu SImulieren
    //feuer = new Feuer(100 , 100 + 20*i); // Konstante Position zum Testen

    simulation->addiereFeuerUmgebung(feuer);
    simulation->setRoboter(roboter);
    simulation->startBewegung(0.5f);

    scene->addItem(feuer);
    }

    double distance = feuer->berechneAbstand(roboter->getCenterPosition());
    double temperature = simulation->erzeugeTemperatur(roboter->getCenterPosition());
    
    qDebug() << "Entfernung:" << distance;
    qDebug() << "Temperatur am Roboter:" << temperature;
}

MainWindow::~MainWindow()
{
    delete ui;
}
