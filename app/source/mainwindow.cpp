#include "mainwindow.h"
#include "NormalKamera.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "simulation.h"
#include <QRandomGenerator>
#include <QGraphicsView>
#include "Hauptdisplay.h"
#include "xmlHandler.h"
#include "qpixmap.h"
#include "QFile"
#include <cstdint>
#include "WaermeKameraDisplay.h"
#include "Waermekamera.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    waermekameraIstAktiv = false;
    waermekameraDisplay = new WaermekameraDisplay(ui->WaermeKamera);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::zeigeBild);
    waermeTimer = new QTimer(this);
    connect(waermeTimer, &QTimer::timeout, this, &MainWindow::zeigeWaermeBild);

      // Sensor starten (wenn notwendig)
        tempSensor.starten();

        // Temperaturanzeige regelmäßig aktualisieren
        QTimer *tempTimer = new QTimer(this);
        connect(tempTimer, &QTimer::timeout, this, &MainWindow::zeigeTemp);
        tempTimer->start(1000);  // alle 1000 ms (1 Sekunde)

        // Optional: erste Anzeige sofort
        zeigeTemp();

    Simulation  * simulation = new Simulation();
    QPixmap pixmap(":/data/umgebung.png");

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

    SimulationManager.ladeXmlSimulation(":/data/umgebung.xml", *simulation);
    simulation->addiereElementeScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonEinschalten_clicked() {
    DisAktiv = true;
    hauptDisplay.einschalten();
}
void MainWindow::on_pushButtonAusschalten_clicked() {
    DisAktiv = false;
    timer->stop();
    kamera.setAktiv(false);
    ui->NormalKamera->clear();
    //ui->NormalAnAus->setChecked(false);
    ui->WaermeKamera->clear();
    //ui->WarmAnAus->setChecked(false);
    ui->NormalAnAus->setChecked(false);

   
}

void MainWindow::on_NormalAnAus_toggled()
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

void MainWindow::zeigeTemp() {
    tempSensor.starten();

    float temperatur = tempSensor.getLetzteMessung();

    if (ui->Temperatur) {
        ui->Temperatur->setText(QString::number(temperatur, 'f', 2) + " °C");
    }
}

void MainWindow::on_WarmAnAus_clicked()
{
    if (!DisAktiv){
        ui->WarmAnAus->setChecked(false);
        ui->WaermeKamera->clear();
        return;
    }
    static bool istAn = false;
    istAn = !istAn;
    if (istAn) {
        waermekamera.wSchalten();
        waermeTimer->start(100);
        uint8_t* bild = waermekamera.fotoMachen(0);
        waermekameraDisplay->waermeBildAnzeigen(bild);
        delete[] bild;
    } else {
        waermeTimer->stop();
;
    }
}
void MainWindow::zeigeWaermeBild() {

    bool Aktiv = waermekamera.wSchalten();
    if (Aktiv) {
        waermeTimer->start(100);
        qDebug()<< "wKamera ist eingeschaltet";
    }else{
        waermeTimer->stop();
        qDebug()<< "wKamera ist ausgeschaltet";
    }
    uint8_t* data = waermekamera.fotoMachen(0);
    if (!data ) return;
    waermekameraDisplay->waermeBildAnzeigen(data);
    delete[] data;
}
