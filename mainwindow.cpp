#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "simulation.h"
#include "SimulationRoboter.h"
#include <QRandomGenerator>
#include <QGraphicsView>
#include "Hauptdisplay.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Simulation  * simulation = new Simulation();
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0, 0, 400, 300);

    roboter = new Roboter(50, 100);
    scene->addItem(roboter);
    for(int i = 0; i < 5;i++){
        // Zufaellige Zahlen fuer die Position um verschiedene Umgebungen zu SImulieren
        feuer = new Feuer(QRandomGenerator::global()->bounded(0, 500), QRandomGenerator::global()->bounded(0, 200));
        //feuer = new Feuer(100 , 100 + 20*i); // Konstante Position zum Testen

        simulation->addiereFeuerUmgebung(feuer);
        //simulation->setRoboter(roboter);

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

