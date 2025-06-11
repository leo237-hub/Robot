#include "mainwindow.h"
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

    Simulation  * simulation = new Simulation();
    QPixmap pixmap(":/data/resources/umgebung.png");

    // Ridimensiona l'immagine a una dimensione più piccola (ad esempio 400x300)
    QPixmap scaledPixmap = pixmap.scaled(800, 261, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    scene = new QGraphicsScene(this);
    scene->addPixmap(scaledPixmap);

    ui->graphicsView->setScene(scene);

    roboter = new Roboter(50, 100);
    scene->addItem(roboter);
    xmlHandler SimulationManager ;

    SimulationManager.ladeXmlSimulation(":/data/resources/umgebung.xml", *simulation);
    simulation->addiereElementeScene(scene);

    //TEST temperatur SENSOR
    QPointF sensorPos(50, 100);

    sensor.setTemperaturQuelle([simulation, sensorPos]() {
        return simulation->erzeugeTemperatur(sensorPos);
    });

    sensor.starten();

    // Anfangswert (noch Standard)
    qDebug() << "Temperatur Sensor Startwert:" << sensor.getLetzteMessung();

    // 10ms später: richtiger Sensorwert
    QTimer::singleShot(10, this, [this]() {
        qDebug() << "Temperatur Sensor (nach 10ms):" << sensor.getLetzteMessung();
    });
    //END TEST

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

