#pragma once
#include <QMainWindow>
#include <QGraphicsScene>
#include "WaermeKameraDisplay.h"
#include "Waermekamera.h"
#include "simulation/feuer.h"
#include "roboter.h"
#include "Hauptdisplay.h"
#include "SimulationRoboter.h"
#include "NormalKamera.h"
#include <QShortcut>
#include <QMediaPlayer>
#include "Lautsprecher.h"

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

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    Roboter* roboter;
    Feuer* feuer;
    HauptDisplay hauptDisplay;
    NormalKamera kamera;
    WaermeKamera waermekamera;
    WaermekameraDisplay *waermekameraDisplay;
    QTimer* timer;
    QTimer* waermeTimer;
    SimRoboter *ctrl {nullptr};
    bool DisAktiv = false;
    TemperaturSensor sensor;
    bool waermekameraIstAktiv = false;
    QMediaPlayer* player;
    Lautsprecher* lautsprecher;


private slots:
    void on_pushButtonEinschalten_clicked();
    void on_pushButtonAusschalten_clicked();
    void zeigeBild();
    void zeigeWaermeBild();
    void on_NormalAnAus_toggled(bool);
    void on_WarmAnAus_clicked();  
    void on_sprechButton_toggled(bool checked);
};


