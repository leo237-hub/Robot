/*
Zweck und Verhalten der MainWindow-Klasse

Zweck:
Hauptfenster der grafischen Benutzeroberfläche, das alle visuellen und logischen Komponenten des Roboters integriert.

Verhalten:
Verwaltet die Interaktion zwischen Benutzer, Roboter und Sensoren, steuert die Anzeige und verarbeitet Benutzereingaben.
*/
#pragma once
#include <QMainWindow>
#include <QGraphicsScene>
#include "WaermeKameraDisplay.h"
#include "../logik/Waermekamera.h"
#include "simulation/feuer.h"
#include "GraphischesRoboter.h"
#include "../logik/Hauptdisplay.h"
#include "SimulationRoboter.h"
#include "NormalKamera.h"
#include <QShortcut>
#include "GpsSensor.h"
#include "TemperaturSensor.h"
#include "Gassensor.h"
#include "Wassersensor.h"
#include "LEDPanel.h"
#include "lampe.h"
#include "Lidarsensor.h"
#include "simulation.h"
#include "../logik/MittelWerter.h"
#include "paketfach.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
    void roboterFokusWiederherstellen();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    GraphischesRoboter* roboter;
    Feuer* feuer;
    HauptDisplay hauptDisplay;
    NormalKamera kamera;
    WaermeKamera waermekamera;
    WaermekameraDisplay *waermekameraDisplay;
    QTimer* timer;
    QTimer* waermeTimer;
    SimRoboter *ctrl {nullptr};
    bool DisAktiv = false;
    TemperaturSensor tempSensor;
    bool waermekameraIstAktiv = false;
    GPSSensor* gpsSensor;
    LEDPanel* ledPanel;
    GasSensor gasSensor;
    Wassersensor wasserSensor;
    Lampe lampe;
    Simulation* simulation;
    LidarSensor* lidarSensor;
    // Sensori ridondanti come membri
    TemperaturSensor* tempSensorArr[3];
    // MittelWerter per la temperatura
    MittelWerter<TemperaturSensor>* mittelwertTemp = nullptr;
    MittelWerter<GasSensor>* mittelwertGas = nullptr;
    MittelWerter<Wassersensor>* mittelwertWasser = nullptr;
    MittelWerter<GPSSensor>* mittelwertGPS = nullptr;
    PaketFach paketfach;
    void updateLidar();
    
    // Variablen um den tatsächlichen Status der Kameras zu verfolgen
    bool normalKameraIstAktiv = false;
    bool waermeKameraIstAktiv = false;
    bool lampeIstAktiv = false;

private slots:
    void on_pushButtonEinschalten_clicked();
    void zeigeBild();
    void zeigeWaermeBild();
    void on_NormalAnAus_toggled();
    void on_WarmAnAus_clicked();
    void on_LampeAnAus_clicked();
    void zeigeTemp();
    void zeigeGPS();
    void zeigeGas();
    void zeigeWasser();
    void motorLEDsAktualisieren();
    void on_PaketfachAnAus_clicked();
};


