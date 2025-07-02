#include "mainwindow.h"
#include "NormalKamera.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QKeyEvent>
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
#include "GraphischesRoboter.h"
#include "SimulationRoboter.h"
#include "TemperaturSensor.h"
#include "GpsSensor.h"
#include "LEDPanel.h"
#include "Gassensor.h"
#include "Lidarsensor.h"
#include "simulationElement.h"
#include <algorithm>
#include "MittelWerter.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    /* App in Vollbildmodus öffnen */
    showFullScreen();
    
    /* Focus Policy setzen damit Tastatur-Events immer empfangen werden */
    setFocusPolicy(Qt::StrongFocus);
    setFocus();
    
    waermekameraIstAktiv = false;
    waermekameraDisplay = new WaermekameraDisplay(ui->WaermeKamera);
    
    /* LED Panel erstellen */
    ledPanel = new LEDPanel(this);
    ledPanel->setGeometry(850, 20, 150, 600);
    ledPanel->show();
    
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::zeigeBild);
    waermeTimer = new QTimer(this);
    connect(waermeTimer, &QTimer::timeout, this, &MainWindow::zeigeWaermeBild);

    Simulation* simulation = new Simulation();
    QPixmap pixmap(":/data/umgebung.png");

    QPixmap scaledPixmap = pixmap.scaled(800, 261, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    scene = new QGraphicsScene(this);
    scene->addPixmap(scaledPixmap);

    ui->graphicsView->setScene(scene);

    // --- Inizializza array di 3 sensori condivisi ---
    LidarSensor* lidarSensorArr[3];
    GPSSensor* gpsSensorArr[3];
    GasSensor* gasSensorArr[3];
    Wassersensor* wasserSensorArr[3];
    Kettensensor* ketteSensorArr[3];
    for (int i = 0; i < 3; ++i) {
        tempSensorArr[i] = new TemperaturSensor();
        lidarSensorArr[i] = new LidarSensor(100.0, 360);
        gpsSensorArr[i] = new GPSSensor();
        gasSensorArr[i] = new GasSensor();
        wasserSensorArr[i] = new Wassersensor();
        ketteSensorArr[i] = new Kettensensor();
    }
    gpsSensor = gpsSensorArr[0];
    lidarSensor = lidarSensorArr[0];
    for (int i = 0; i < 3; ++i) {
        tempSensorArr[i]->setTemperaturQuelle([this, simulation]() {
            if (!gpsSensor) return 20.0f;
            return simulation->erzeugeTemperatur(QPointF(gpsSensor->getX(), gpsSensor->getY()));
        });
        gasSensorArr[i]->setGasQuelle([this, simulation]() {
            if (!gpsSensor) return 5.0f;
            return simulation->erzeugeGasKonzentration(QPointF(gpsSensor->getX(), gpsSensor->getY()));
        });
        wasserSensorArr[i]->setWasserQuelle([this, simulation]() {
            if (!gpsSensor) return 50.0f;
            return simulation->erzeugeWasserKonzentration(QPointF(gpsSensor->getX(), gpsSensor->getY()));
        });
        tempSensorArr[i]->starten();
        gasSensorArr[i]->starten();
        wasserSensorArr[i]->starten();
    }
    // Member-GasSensor an Simulation koppeln
    gasSensor.setGasQuelle([this, simulation]() {
        if (!gpsSensor) return 5.0f;
        return simulation->erzeugeGasKonzentration(QPointF(gpsSensor->getX(), gpsSensor->getY()));
    });
    gasSensor.starten();
    roboter = new GraphischesRoboter(tempSensorArr, lidarSensorArr, gpsSensorArr, gasSensorArr, wasserSensorArr, ketteSensorArr, 50, 100, 40);
    scene->addItem(roboter);
    roboter->setFocus();
    roboter->setLEDPanel(ledPanel);
    roboter->setzeRoboterAktiv(false);
    
    /* LED Status aktualisieren - Roboter ist inaktiv, GPS ist aktiv */
    ledPanel->setzeRoboterStatus(false);
    ledPanel->setzeGPSStatus(true);
    
    xmlHandler SimulationManager;
    ctrl = new SimRoboter(this);
    ctrl->setRoboter(roboter);

    SimulationManager.ladeXmlSimulation(":/data/umgebung.xml", *simulation);
    simulation->addiereElementeScene(scene);

    /* Temperaturanzeige regelmäßig aktualisieren */
    QTimer *tempTimer = new QTimer(this);
    connect(tempTimer, &QTimer::timeout, this, &MainWindow::zeigeTemp);
    tempTimer->start(1000);  /* alle 1000 ms (1 Sekunde) */
    zeigeTemp(); /*optional*/

    QTimer *gpsTimer = new QTimer(this);
    connect(gpsTimer, &QTimer::timeout, this, &MainWindow::zeigeGPS);
    gpsTimer->start(1000);
    zeigeGPS();
    
    /* Gasanzeige regelmäßig aktualisieren */
    QTimer *gasTimer = new QTimer(this);
    connect(gasTimer, &QTimer::timeout, this, &MainWindow::zeigeGas);
    gasTimer->start(1000);  /* alle 1000 ms (1 Sekunde) */
    zeigeGas(); /*optional*/
    
    /* Wasseranzeige regelmäßig aktualisieren */
    QTimer *wasserTimer = new QTimer(this);
    connect(wasserTimer, &QTimer::timeout, this, &MainWindow::zeigeWasser);
    wasserTimer->start(1000);  /* alle 1000 ms (1 Sekunde) */
    zeigeWasser(); /*optional*/
    
    /* Timer für Motor LED Aktualisierungen */
    QTimer *motorLEDTimer = new QTimer(this);
    connect(motorLEDTimer, &QTimer::timeout, this, &MainWindow::motorLEDsAktualisieren);
    motorLEDTimer->start(100); /* Alle 100ms aktualisieren */

    QTimer* lidarTimer = new QTimer(this);
    connect(lidarTimer, &QTimer::timeout, this, &MainWindow::updateLidar);
    lidarTimer->start(100); // alle 100ms aktualisieren

    std::vector<TemperaturSensor*> tempSensorVec;
    for (int i = 0; i < 3; ++i) tempSensorVec.push_back(tempSensorArr[i]);
    mittelwertTemp = new MittelWerter<TemperaturSensor>(tempSensorVec);

    std::vector<GasSensor*> gasSensorVec;
    for (int i = 0; i < 3; ++i) gasSensorVec.push_back(gasSensorArr[i]);
    mittelwertGas = new MittelWerter<GasSensor>(gasSensorVec);

    std::vector<Wassersensor*> wasserSensorVec;
    for (int i = 0; i < 3; ++i) wasserSensorVec.push_back(wasserSensorArr[i]);
    mittelwertWasser = new MittelWerter<Wassersensor>(wasserSensorVec);

    std::vector<GPSSensor*> gpsSensorVec;
    for (int i = 0; i < 3; ++i) gpsSensorVec.push_back(gpsSensorArr[i]);
    mittelwertGPS = new MittelWerter<GPSSensor>(gpsSensorVec);
}

MainWindow::~MainWindow()
{
    if (mittelwertTemp) {
        delete mittelwertTemp;
    }
    if (mittelwertGas) {
        delete mittelwertGas;
    }
    if (mittelwertWasser) {
        delete mittelwertWasser;
    }
    delete ui;
}

void MainWindow::updateLidar() {
    if (!lidarSensor) {
        return;
    }
    if (!roboter) {
        return;
    }
    if (!scene) {
        return;
    }
    if (!ctrl) {
        return;
    }
    // Roboterposition holen (aus GPS oder Simulation)
    double roboterX = 0.0;
    double roboterY = 0.0;
    if (gpsSensor) {
        roboterX = gpsSensor->getX();
        roboterY = gpsSensor->getY();
    }
    lidarSensor->setzePosition(roboterX, roboterY);
    auto items = scene->items();
    std::vector<Obstacle> obstacles;
    int simElemCount = 0;
    for (QGraphicsItem* item : items) {
        simulationElement* element = dynamic_cast<simulationElement*>(item);
        if (element) {
            simElemCount++;
            if (element->istSolid()) {
                Obstacle obs;
                obs.x = element->getX();
                obs.y = element->getY();
                obs.radius = element->holeRadius();
                obstacles.push_back(obs);
            }
        }
    }
    lidarSensor->update(obstacles);
    const double sicherheitsAbstand = 45.0;
    bool vorne = lidarSensor->istHindernisVorne(sicherheitsAbstand);
    if (vorne) {
        roboter->setzeBlockVorwaerts(true);
    } else {
        roboter->setzeBlockVorwaerts(false);
    }
}

void MainWindow::on_pushButtonEinschalten_clicked() {
    bool istAktiv = ui->pushButtonEinschalten->isChecked();
    
    if (istAktiv) {
        /* System einschalten */
    DisAktiv = true;
    hauptDisplay.einschalten();
        
        /* Roboter aktivieren */
        if (roboter) {
            roboter->setzeRoboterAktiv(true);
        }
        
        /* LED Status aktualisieren */
        ledPanel->setzeRoboterStatus(true);
        
        /* Stile blu für aktiven Zustand */
        ui->pushButtonEinschalten->setStyleSheet(
            "QPushButton { background-color: #0078d4; color: white; border: 2px solid #005a9e; }"
            "QPushButton:hover { background-color: #106ebe; }"
            "QPushButton:pressed { background-color: #005a9e; }"
        );
        
    } else {
        /* System ausschalten */
    DisAktiv = false;
        
        /* Roboter deaktivieren */
        if (roboter) {
            roboter->setzeRoboterAktiv(false);
        }
        
        /* Timer stoppen */
    timer->stop();
        waermeTimer->stop();
        
        /* Kameras ausschalten */
    kamera.setAktiv(false);
        waermekamera.wSchalten(); /* Wärmekamera ausschalten */
        
        /* Lampe ausschalten */
        lampe.ausschalten();
        
        /* Displays leeren */
    ui->NormalKamera->clear();
    ui->WaermeKamera->clear();
        
        /* Button-States zurücksetzen */
    ui->NormalAnAus->setChecked(false);
        ui->WarmAnAus->setChecked(false);
        ui->LampeAnAus->setChecked(false);
        
        /* LED-Status zurücksetzen */
        ledPanel->setzeKameraStatus(false);
        ledPanel->setzeWaermeKameraStatus(false);
        ledPanel->setzeLampeStatus(false);
        
        /* Kamera-Status-Variablen zurücksetzen */
        normalKameraIstAktiv = false;
        waermeKameraIstAktiv = false;
        lampeIstAktiv = false;
        
        /* LED Status aktualisieren */
        ledPanel->setzeRoboterStatus(false);
        
        /* Stile standard für inaktiven Zustand */
        ui->pushButtonEinschalten->setStyleSheet("");
        
    }
}

void MainWindow::on_NormalAnAus_toggled()
{
    if (!DisAktiv){
        ui->NormalAnAus->setChecked(false);
        ui->NormalKamera->clear(); /* Schwarzer Bildschirm wenn nicht aktiv */
        normalKameraIstAktiv = false;
        return;
    }
    
    /* Toggle basierend auf dem aktuellen Zustand des Buttons */
    bool buttonChecked = ui->NormalAnAus->isChecked();
    
    if (buttonChecked && !normalKameraIstAktiv) {
        /* Kamera einschalten */
        kamera.setAktiv(true);
        timer->start(100);
        ledPanel->setzeKameraStatus(true);
        normalKameraIstAktiv = true;
    } else if (!buttonChecked && normalKameraIstAktiv) {
        /* Kamera ausschalten */
        kamera.setAktiv(false);
        timer->stop();
        ledPanel->setzeKameraStatus(false);
        ui->NormalKamera->clear(); /* Schwarzer Bildschirm wenn ausgeschaltet */
        normalKameraIstAktiv = false;
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
    if (!DisAktiv) {
        if (ui->TemperaturLabel) ui->TemperaturLabel->setText("---");
        return;
    }
    float temperatur = mittelwertTemp ? mittelwertTemp->getMittelwert() : 0.0f;
    if (ui->TemperaturLabel) {
        ui->TemperaturLabel->setText(QString::number(temperatur, 'f', 2) + " °C");
    }
}

void MainWindow::zeigeGPS() {
    if (!DisAktiv) {
        if (ui->GPSLabel) ui->GPSLabel->setText("---");
        return;
    }
    if (!mittelwertGPS) return;
    double x = mittelwertGPS->getMittelwertX();
    double y = mittelwertGPS->getMittelwertY();
    if (ui->GPSLabel) {
        ui->GPSLabel->setText(QString("x:%1, y:%2").arg(x, 0, 'f', 1).arg(y, 0, 'f', 1));
    }
}

void MainWindow::zeigeGas() {
    if (!DisAktiv) {
        if (ui->GasLabel) ui->GasLabel->setText("---");
        return;
    }
    float gasWert = mittelwertGas ? mittelwertGas->getMittelwert() : 0.0f;
    QString gasText = QString("%1%" ).arg(gasWert, 0, 'f', 1);
    if (ui->GasLabel) {
        ui->GasLabel->setText(gasText);
    }
}

void MainWindow::zeigeWasser() {
    if (!DisAktiv) {
        if (ui->WasserLabel) ui->WasserLabel->setText("---");
        return;
    }
    float wasserWert = mittelwertWasser ? mittelwertWasser->getMittelwert() : 0.0f;
    QString wasserText = QString("%1" ).arg(wasserWert, 0, 'f', 1);
    if (ui->WasserLabel) {
        ui->WasserLabel->setText(wasserText);
    }
}

void MainWindow::motorLEDsAktualisieren() {
    if (!roboter) return;
    if (!DisAktiv) {
        ledPanel->setzeMotorStatus(false);
        ledPanel->setzeDrehmotorStatus(false);
        return;
    }
    bool motorActive = roboter->bewegtSich();
    ledPanel->setzeMotorStatus(motorActive);
    // Drehemotor-LED NICHT mehr automatisch setzen!
}

void MainWindow::on_WarmAnAus_clicked()
{
    if (!DisAktiv){
        ui->WarmAnAus->setChecked(false);
        ui->WaermeKamera->clear();
        waermeKameraIstAktiv = false;
        return;
    }
    
    /* Toggle basierend auf dem aktuellen Zustand des Buttons */
    bool buttonChecked = ui->WarmAnAus->isChecked();
    
    if (buttonChecked && !waermeKameraIstAktiv) {
        /* Wärmekamera einschalten */
        waermekamera.wSchalten();
        waermeTimer->start(100);
        ledPanel->setzeWaermeKameraStatus(true);
        waermeKameraIstAktiv = true;
    } else if (!buttonChecked && waermeKameraIstAktiv) {
        /* Wärmekamera ausschalten */
        waermekamera.wSchalten();
        waermeTimer->stop();
        ledPanel->setzeWaermeKameraStatus(false);
        ui->WaermeKamera->clear(); /* Schwarzer Bildschirm wenn ausgeschaltet */
        waermeKameraIstAktiv = false;
    }
}

void MainWindow::on_LampeAnAus_clicked()
{
    if (!DisAktiv){
        ui->LampeAnAus->setChecked(false);
        lampeIstAktiv = false;
        return;
    }
    
    /* Toggle basierend auf dem aktuellen Zustand des Buttons */
    bool buttonChecked = ui->LampeAnAus->isChecked();
    
    if (buttonChecked && !lampeIstAktiv) {
        /* Lampe einschalten */
        lampe.einschalten();
        ledPanel->setzeLampeStatus(true);
        lampeIstAktiv = true;
    } else if (!buttonChecked && lampeIstAktiv) {
        /* Lampe ausschalten */
        lampe.ausschalten();
        ledPanel->setzeLampeStatus(false);
        lampeIstAktiv = false;
    }
}

void MainWindow::zeigeWaermeBild() {
    if (!waermeKameraIstAktiv) return;
    
    uint8_t* data = waermekamera.fotoMachen(0);
    if (!data) return;
    
    waermekameraDisplay->waermeBildAnzeigen(data);
    delete[] data;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    /* Vollbildmodus umschalten mit F11 - funktioniert immer */
    if (event->key() == Qt::Key_F11) {
        /* Focus sicherstellen damit F11 immer funktioniert */
        if (!hasFocus()) {
            setFocus();
        }
        
        if (isFullScreen()) {
            showNormal();
        } else {
            showFullScreen();
        }
        event->accept();
        return;
    }
    
    /* Vollbildmodus mit Escape verlassen - funktioniert immer */
    if (event->key() == Qt::Key_Escape && isFullScreen()) {
        /* Focus sicherstellen damit Escape immer funktioniert */
        if (!hasFocus()) {
            setFocus();
        }
        
        showNormal();
        event->accept();
        return;
    }
    
    /* Roboter-Kontrollen nur wenn Roboter verfügbar ist */
    if (!roboter) {
        QMainWindow::keyPressEvent(event);
        return;
    }
    
    /* Roboter-Fokus automatisch wiederherstellen bei WASD-Tasten */
    switch(event->key()) {
    case Qt::Key_J: // 'J' drehen links
        if (roboter) {
            roboter->dreheKopfLinks();
            ledPanel->setzeDrehmotorStatus(true);
        }
        event->accept();
        return;
    case Qt::Key_L: // 'L' drehen rechts
        if (roboter) {
            roboter->dreheKopfRechts();
            ledPanel->setzeDrehmotorStatus(true);
        }
        event->accept();
        return;
    case Qt::Key_W:
    case Qt::Key_Up:
    case Qt::Key_A:
    case Qt::Key_Left:
    case Qt::Key_S:
    case Qt::Key_Down:
    case Qt::Key_D:
    case Qt::Key_Right:
        if (!roboter) break;
        if (!roboter->hasFocus()) {
            roboter->setFocus();
        }
        roboter->tastaturDruckBehandeln(event);
        event->accept();
        return;
    default:
        QMainWindow::keyPressEvent(event);
        break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    if (!roboter) {
        QMainWindow::keyReleaseEvent(event);
        return;
    }
    
    /* Roboter-Fokus automatisch wiederherstellen bei WASD-Tasten */
    switch(event->key()) {
    case Qt::Key_W:
    case Qt::Key_Up:
    case Qt::Key_A:
    case Qt::Key_Left:
    case Qt::Key_S:
    case Qt::Key_Down:
    case Qt::Key_D:
    case Qt::Key_Right:
        if (!roboter->hasFocus()) {
            roboter->setFocus();
        }
        roboter->tastaturLoslassenBehandeln(event);
        event->accept();
        return;
    case Qt::Key_J: // 'J' loslassen
    case Qt::Key_L: // 'L' loslassen
        ledPanel->setzeDrehmotorStatus(false);
        event->accept();
        return;
    default:
        QMainWindow::keyReleaseEvent(event);
        break;
    }
}

void MainWindow::roboterFokusWiederherstellen() {
    if (roboter) {
        roboter->setFocus();
    }
}

void MainWindow::on_PaketfachAnAus_clicked()
{
    if (!DisAktiv){
        ui->PaketfachAnAus->setChecked(false);
        ledPanel->setzePaketfachStatus(false);
        return;
    }
    bool buttonChecked = ui->PaketfachAnAus->isChecked();
    if (buttonChecked) {
        // Paketfach öffnen
        paketfach.Oeffnen();
        ledPanel->setzePaketfachStatus(true);
    } else {
        // Paketfach schließen
        paketfach.Schliessen();
        ledPanel->setzePaketfachStatus(false);
    }
}
