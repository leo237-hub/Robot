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
#include <algorithm>

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

    gpsSensor = new GPSSensor();
    roboter = new GraphischesRoboter(50, 100, 40, gpsSensor);
    scene->addItem(roboter);
    roboter->setFocus();
    
    /* Roboter inizialmente deaktiviert (System ist aus) */
    roboter->setzeRoboterAktiv(false);
    
    /* LED Status aktualisieren - Roboter ist inaktiv, GPS ist aktiv */
    ledPanel->setzeRoboterStatus(false);
    ledPanel->setzeGPSStatus(true);
    
    xmlHandler SimulationManager;
    ctrl = new SimRoboter(this);
    ctrl->setRoboter(roboter);

    SimulationManager.ladeXmlSimulation(":/data/umgebung.xml", *simulation);
    simulation->addiereElementeScene(scene);

    /* Verbinde TemperaturSensor mit der Simulation */
    tempSensor.setTemperaturQuelle([this, simulation]() {
        if (!gpsSensor) return 20.0f;
        QPointF robotPosition(gpsSensor->getX(), gpsSensor->getY());
        return simulation->erzeugeTemperatur(robotPosition);
    });

    tempSensor.starten();

    /* LED Status aktualisieren - Temperatursensor ist aktiv */
    ledPanel->setzeTemperaturSensorStatus(true);

    /* Verbinde GasSensor mit der Simulation */
    gasSensor.setGasQuelle([this, simulation]() {
        if (!gpsSensor) return 5.0f; // Hintergrund-Gaskonzentration
        QPointF robotPosition(gpsSensor->getX(), gpsSensor->getY());
        return simulation->erzeugeGasKonzentration(robotPosition);
    });

    gasSensor.starten();

    /* LED Status aktualisieren - Gassensor ist aktiv */
    ledPanel->setzeGassensorStatus(true);

    /* Verbinde Wassersensor mit der Simulation */
    wasserSensor.setWasserQuelle([this, simulation]() {
        if (!gpsSensor) return 50.0f; // Standard Luftfeuchtigkeit 50%
        QPointF robotPosition(gpsSensor->getX(), gpsSensor->getY());
        return simulation->erzeugeWasserKonzentration(robotPosition);
    });

    wasserSensor.starten();

    /* LED Status aktualisieren - Wassersensor ist aktiv */
    ledPanel->setzeWassersensorStatus(true);

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
}

MainWindow::~MainWindow()
{
    delete ui;
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
        
        qDebug() << "System eingeschaltet";
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
        
        qDebug() << "System ausgeschaltet - alle Kameras und Roboter deaktiviert";
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
        qDebug() << "Kamera ist eingeschaltet";
    } else if (!buttonChecked && normalKameraIstAktiv) {
        /* Kamera ausschalten */
        kamera.setAktiv(false);
        timer->stop();
        ledPanel->setzeKameraStatus(false);
        ui->NormalKamera->clear(); /* Schwarzer Bildschirm wenn ausgeschaltet */
        normalKameraIstAktiv = false;
        qDebug() << "Kamera ist ausgeschaltet";
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

void MainWindow::zeigeGPS() {
    if (!gpsSensor) return;

    double x = gpsSensor->getX();
    double y = gpsSensor->getY();

    QString gpsText = QString("GPS: x:%1, y:%2").arg(x, 0, 'f', 1).arg(y, 0, 'f', 1);
    
    // Display GPS coordinates in label_3
    if (ui->label_3) {
        ui->label_3->setText(gpsText);
    }
}

void MainWindow::zeigeGas() {
    gasSensor.starten();

    float gasWert = gasSensor.getLetzteMessung();

    QString gasText = QString("Gas: %1%").arg(gasWert, 0, 'f', 1);
    
    // Display gas values in the existing UI label
    if (ui->label) {
        ui->label->setText(gasText);
    }
}

void MainWindow::zeigeWasser() {
    wasserSensor.starten();

    float wasserWert = wasserSensor.getLetzteMessung();

    QString wasserText = QString("Wasser: %1%").arg(wasserWert, 0, 'f', 1);
    
    // Display water/humidity values in label_2
    if (ui->label_2) {
        ui->label_2->setText(wasserText);
    }
}

void MainWindow::motorLEDsAktualisieren() {
    if (!roboter) return;
    
    /* Prüfen ob Roboter aktiv ist */
    if (!DisAktiv) {
        /* Roboter ist ausgeschaltet - Motoren LEDs aus */
        ledPanel->setzeMotorStatus(false);
        ledPanel->setzeDrehmotorStatus(false);
        return;
    }
    
    /* Prüfen ob Roboter sich bewegt (Motor aktiv) */
    bool motorActive = roboter->bewegtSich();
    ledPanel->setzeMotorStatus(motorActive);
    
    /* Für jetzt, Drehmotor LED basierend auf Bewegung setzen */
    /* In einer echten Implementierung würdest du den tatsächlichen Drehmotor-Status prüfen */
    ledPanel->setzeDrehmotorStatus(motorActive);
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
        qDebug() << "Wärmekamera ist eingeschaltet";
    } else if (!buttonChecked && waermeKameraIstAktiv) {
        /* Wärmekamera ausschalten */
        waermekamera.wSchalten();
        waermeTimer->stop();
        ledPanel->setzeWaermeKameraStatus(false);
        ui->WaermeKamera->clear(); /* Schwarzer Bildschirm wenn ausgeschaltet */
        waermeKameraIstAktiv = false;
        qDebug() << "Wärmekamera ist ausgeschaltet";
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
        qDebug() << "Lampe ist eingeschaltet";
    } else if (!buttonChecked && lampeIstAktiv) {
        /* Lampe ausschalten */
        lampe.ausschalten();
        ledPanel->setzeLampeStatus(false);
        lampeIstAktiv = false;
        qDebug() << "Lampe ist ausgeschaltet";
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
    case Qt::Key_W:
    case Qt::Key_Up:
    case Qt::Key_A:
    case Qt::Key_Left:
    case Qt::Key_S:
    case Qt::Key_Down:
    case Qt::Key_D:
    case Qt::Key_Right:
        /* Fokus automatisch wiederherstellen */
        if (!roboter->hasFocus()) {
            roboter->setFocus();
            qDebug() << "Roboter-Fokus automatisch wiederhergestellt";
        }
        /* Event an den Roboter weiterleiten */
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
        /* Fokus automatisch wiederherstellen */
        if (!roboter->hasFocus()) {
            roboter->setFocus();
            qDebug() << "Roboter-Fokus automatisch wiederhergestellt";
        }
        /* Event an den Roboter weiterleiten */
        roboter->tastaturLoslassenBehandeln(event);
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
        qDebug() << "Roboter-Fokus wiederhergestellt";
    }
}
