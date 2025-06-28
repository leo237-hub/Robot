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


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    waermekameraIstAktiv = false;
    waermekameraDisplay = new WaermekameraDisplay(ui->WaermeKamera);
    
    // LED Panel erstellen
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
    
    // Roboter inizialmente deaktiviert (System ist aus)
    roboter->setzeRoboterAktiv(false);
    
    // LED Status aktualisieren - Roboter ist inaktiv, GPS ist aktiv
    ledPanel->setzeRoboterStatus(false);
    ledPanel->setzeGPSStatus(true);
    
    xmlHandler SimulationManager;
    ctrl = new SimRoboter(this);
    ctrl->setRoboter(roboter);

    SimulationManager.ladeXmlSimulation(":/data/umgebung.xml", *simulation);
    simulation->addiereElementeScene(scene);

    // Verbinde TemperaturSensor mit der Simulation
    tempSensor.setTemperaturQuelle([this, simulation]() {
        if (!gpsSensor) return 20.0f;
        QPointF robotPosition(gpsSensor->getX(), gpsSensor->getY());
        return simulation->erzeugeTemperatur(robotPosition);
    });

    tempSensor.starten();

    // LED Status aktualisieren - Temperatursensor ist aktiv
    ledPanel->setzeTemperaturSensorStatus(true);

    // Temperaturanzeige regelmäßig aktualisieren
    QTimer *tempTimer = new QTimer(this);
    connect(tempTimer, &QTimer::timeout, this, &MainWindow::zeigeTemp);
    tempTimer->start(1000);  // alle 1000 ms (1 Sekunde)
    zeigeTemp(); //optional

    QTimer *gpsTimer = new QTimer(this);
    connect(gpsTimer, &QTimer::timeout, this, &MainWindow::zeigeGPS);
    gpsTimer->start(1000);
    zeigeGPS();
    
    // Timer für Motor LED Updates
    QTimer *motorLEDTimer = new QTimer(this);
    connect(motorLEDTimer, &QTimer::timeout, this, &MainWindow::updateMotorLEDs);
    motorLEDTimer->start(100); // Alle 100ms aktualisieren
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonEinschalten_clicked() {
    bool istAktiv = ui->pushButtonEinschalten->isChecked();
    
    if (istAktiv) {
        // System einschalten
    DisAktiv = true;
    hauptDisplay.einschalten();
        
        // Roboter aktivieren
        if (roboter) {
            roboter->setzeRoboterAktiv(true);
        }
        
        // LED Status aktualisieren
        ledPanel->setzeRoboterStatus(true);
        
        // Stile blu für aktiven Zustand
        ui->pushButtonEinschalten->setStyleSheet(
            "QPushButton { background-color: #0078d4; color: white; border: 2px solid #005a9e; }"
            "QPushButton:hover { background-color: #106ebe; }"
            "QPushButton:pressed { background-color: #005a9e; }"
        );
        
        qDebug() << "System eingeschaltet";
    } else {
        // System ausschalten
    DisAktiv = false;
        
        // Roboter deaktivieren
        if (roboter) {
            roboter->setzeRoboterAktiv(false);
        }
        
        // Timer stoppen
    timer->stop();
        waermeTimer->stop();
        
        // Kameras ausschalten
    kamera.setAktiv(false);
        waermekamera.wSchalten(); // Wärmekamera ausschalten
        
        // Displays leeren
    ui->NormalKamera->clear();
    ui->WaermeKamera->clear();
        
        // Button-States zurücksetzen
    ui->NormalAnAus->setChecked(false);
        ui->WarmAnAus->setChecked(false);
        
        // LED-Status zurücksetzen
        ledPanel->setzeKameraStatus(false);
        ledPanel->setzeWaermeKameraStatus(false);
        
        // Variabili di stato delle camere resettare
        normalKameraIstAktiv = false;
        waermeKameraIstAktiv = false;
        
        // LED Status aktualisieren
        ledPanel->setzeRoboterStatus(false);
        
        // Stile standard für inaktiven Zustand
        ui->pushButtonEinschalten->setStyleSheet("");
        
        qDebug() << "System ausgeschaltet - alle Kameras und Roboter deaktiviert";
    }
}

void MainWindow::on_NormalAnAus_toggled()
{
    if (!DisAktiv){
        ui->NormalAnAus->setChecked(false);
        ui->NormalKamera->clear(); // Schermo nero wenn nicht aktiv
        normalKameraIstAktiv = false;
        return;
    }
    
    // Toggle basato sullo stato attuale del pulsante
    bool buttonChecked = ui->NormalAnAus->isChecked();
    
    if (buttonChecked && !normalKameraIstAktiv) {
        // Camera einschalten
        kamera.setAktiv(true);
        timer->start(100);
        ledPanel->setzeKameraStatus(true);
        normalKameraIstAktiv = true;
        qDebug() << "Kamera ist eingeschaltet";
    } else if (!buttonChecked && normalKameraIstAktiv) {
        // Camera ausschalten
        kamera.setAktiv(false);
        timer->stop();
        ledPanel->setzeKameraStatus(false);
        ui->NormalKamera->clear(); // Schermo nero wenn ausgeschaltet
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

    QString text = QString("x: %1, y: %2").arg(x, 0, 'f', 1).arg(y, 0, 'f', 1);
    ui->label_2->setText(text);
}

void MainWindow::updateMotorLEDs() {
    if (!roboter) return;
    
    // Prüfen ob Roboter aktiv ist
    if (!DisAktiv) {
        // Roboter ist ausgeschaltet - Motoren LEDs aus
        ledPanel->setzeMotorStatus(false);
        ledPanel->setzeDrehmotorStatus(false);
        return;
    }
    
    // Prüfen ob Roboter sich bewegt (Motor aktiv)
    bool motorActive = roboter->isMoving();
    ledPanel->setzeMotorStatus(motorActive);
    
    // Für jetzt, Drehmotor LED basierend auf Bewegung setzen
    // In einer echten Implementierung würdest du den tatsächlichen Drehmotor-Status prüfen
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
    
    // Toggle basato sullo stato attuale del pulsante
    bool buttonChecked = ui->WarmAnAus->isChecked();
    
    if (buttonChecked && !waermeKameraIstAktiv) {
        // Wärmekamera einschalten
        waermekamera.wSchalten();
        waermeTimer->start(100);
        ledPanel->setzeWaermeKameraStatus(true);
        waermeKameraIstAktiv = true;
        uint8_t* bild = waermekamera.fotoMachen(0);
        waermekameraDisplay->waermeBildAnzeigen(bild);
        delete[] bild;
        qDebug() << "Wärmekamera ist eingeschaltet";
    } else if (!buttonChecked && waermeKameraIstAktiv) {
        // Wärmekamera ausschalten
        waermekamera.wSchalten();
        waermeTimer->stop();
        ledPanel->setzeWaermeKameraStatus(false);
        ui->WaermeKamera->clear(); // Schermo nero wenn ausgeschaltet
        waermeKameraIstAktiv = false;
        qDebug() << "Wärmekamera ist ausgeschaltet";
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

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (!roboter) {
        QMainWindow::keyPressEvent(event);
        return;
    }
    
    // Roboter-Fokus automatisch wiederherstellen bei WASD-Tasten
    switch(event->key()) {
    case Qt::Key_W:
    case Qt::Key_Up:
    case Qt::Key_A:
    case Qt::Key_Left:
    case Qt::Key_S:
    case Qt::Key_Down:
    case Qt::Key_D:
    case Qt::Key_Right:
        // Fokus automatisch wiederherstellen
        if (!roboter->hasFocus()) {
            roboter->setFocus();
            qDebug() << "Roboter-Fokus automatisch wiederhergestellt";
        }
        // Event an den Roboter weiterleiten
        roboter->handleKeyPress(event);
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
    
    // Roboter-Fokus automatisch wiederherstellen bei WASD-Tasten
    switch(event->key()) {
    case Qt::Key_W:
    case Qt::Key_Up:
    case Qt::Key_A:
    case Qt::Key_Left:
    case Qt::Key_S:
    case Qt::Key_Down:
    case Qt::Key_D:
    case Qt::Key_Right:
        // Fokus automatisch wiederherstellen
        if (!roboter->hasFocus()) {
            roboter->setFocus();
            qDebug() << "Roboter-Fokus automatisch wiederhergestellt";
        }
        // Event an den Roboter weiterleiten
        roboter->handleKeyRelease(event);
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
