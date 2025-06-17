#include "mainwindow.h"
#include "NormalKamera.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "simulation.h"
#include "SimulationRoboter.h"
#include <QRandomGenerator>
#include <QGraphicsView>
#include "Hauptdisplay.h"
#include "xmlHandler.h"
#include "qpixmap.h"
#include "QFile"
#include "TemperaturSensor.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::zeigeBild);

    Simulation  * simulation = new Simulation();
    QPixmap pixmap(":/data/resources/umgebung.png");

    QPixmap scaledPixmap = pixmap.scaled(800, 261, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    scene = new QGraphicsScene(this);
    scene->addPixmap(scaledPixmap);

    ui->graphicsView->setScene(scene);

    roboter = new Roboter(50, 100, 40);
    scene->addItem(roboter);
    roboter->setFocus();
    xmlHandler SimulationManager ;
    ctrl = new SimRoboter(this);
    ctrl ->setRoboter(roboter);

    SimulationManager.ladeXmlSimulation(":/data/resources/umgebung.xml", *simulation);
    simulation->addiereElementeScene(scene);

    //TEST temperatur SENSOR
    QPointF sensorPos(50, 100);


}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::on_pushButtonEinschalten_clicked() {
    DisAktiv = true;
    hauptDisplay.einschalten();
    timer->stop();
    kamera.setAktiv(false);
    ui->NormalKamera->clear();
    ui->NormalAnAus->setChecked(false);

}

void MainWindow::on_pushButtonAusschalten_clicked() {
    DisAktiv = false;
    timer->stop();
    kamera.setAktiv(false);
    ui->NormalKamera->clear();
    ui->NormalAnAus->setChecked(false);

   
}
void MainWindow::on_NormalAnAus_toggled(bool checked)
{
    bool Aktiv = kamera.schalten();

    if (!DisAktiv){
        ui->NormalAnAus->setChecked(false);
        return;
    }
    if (Aktiv) {
        timer->start(100);
        qDebug()<< "Kamera ist eingeschaltet";
    }else{
        timer->stop();
        qDebug()<< "Kamera ist ausgeschaltet";
    }
}


void MainWindow::zeigeBild()
{
    uint8_t* rawData = kamera.fotoMachen(0);

    QImage image(rawData, 640, 480, QImage::Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(image);

    ui->NormalKamera->setPixmap(pixmap);

    delete[] rawData;
}


