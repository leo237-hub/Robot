#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "include/simulation/simulation.h"
#include "include/simulation/SimulationRoboter.h"
#include <QRandomGenerator>
#include <QGraphicsView>
#include "include/Hauptdisplay/Hauptdisplay.h"

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
    4. Display done
    5. Joystick
    */

    /*
 * mahle rote punkt als feuer und blaue als roboter
 *
 */
    SimRoboter * simRoboter = new SimRoboter();
    Simulation  * simulation = new Simulation();
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0, 0, 400, 300);

    roboter = new Roboter(50, 100);
    scene->addItem(roboter);
    simRoboter->setRoboter(roboter);
    for(int i = 0; i < 5;i++){
        // Zufaellige Zahlen fuer die Position um verschiedene Umgebungen zu SImulieren
        feuer = new Feuer(QRandomGenerator::global()->bounded(0, 500), QRandomGenerator::global()->bounded(0, 200));
        //feuer = new Feuer(100 , 100 + 20*i); // Konstante Position zum Testen

        simulation->addiereFeuerUmgebung(feuer);
        //simulation->setRoboter(roboter);

        scene->addItem(feuer);
    }

    //Bewegung Einmal starten
    simRoboter->startBewegung(0.5f);

    double distance = feuer->berechneAbstand(roboter->getCenterPosition());
    double temperature = simulation->erzeugeTemperatur(roboter->getCenterPosition());
    qDebug() << "Entfernung:" << distance;
    qDebug() << "Temperatur am Roboter:" << temperature;
}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::on_pushButtonEinschalten_clicked() {
    hauptDisplay.einschalten();

}

void MainWindow::on_pushButtonAusschalten_clicked() {
    hauptDisplay.ausschalten();
    //QLabel = grau
    QPalette pal = ui->labelAnzeige->palette();
    pal.setColor(QPalette::Window, QColor(Qt::gray));
    ui->labelAnzeige->setAutoFillBackground(true);
    ui->labelAnzeige->setPalette(pal);
    ui->labelAnzeige->update();

}
void MainWindow::on_verticalSliderHelligkeit_valueChanged(int value)
{
    if (hauptDisplay.isEingeschaltet()) {
        hauptDisplay.helligkeitAnpassen(value);    // Ferbe ändern je nach der Werte, je höher desto heller
        int grauWert = 255 * value / 100;          // grau
        QColor farbe(grauWert, grauWert, grauWert);
        QPalette pal = ui->labelAnzeige->palette();
        pal.setColor(QPalette::Window, farbe);
        ui->labelAnzeige->setAutoFillBackground(true);
        ui->labelAnzeige->setPalette(pal);
        ui->labelAnzeige->update();
    }
}

