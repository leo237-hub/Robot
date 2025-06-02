#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "simulation.h"
#include "SimulationRoboter.h"
#include <QRandomGenerator>
#include <QGraphicsView>
#include "Hauptdisplay.h"
#include "xmlHandler.h"

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
    xmlHandler SimulationManager ;
    
    SimulationManager.ladeXmlSimulation("./../../resources/umgebung.xml", *simulation);
    for(auto it :simulation->gruppeFeuer){
        scene->addItem(it);
    }


    double temperature = simulation->erzeugeTemperatur(roboter->getCenterPosition());
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

