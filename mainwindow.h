#pragma once
#include <QMainWindow>
#include <QGraphicsScene>
#include "include/simulation/feuer.h"
#include "include/roboter.h"
#include "include/Hauptdisplay/Hauptdisplay.h"
#include "include/simulation/SimulationRoboter.h"
#include "NormalKamera.h"

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
    QTimer* timer;
    bool DisAktiv = false;

private slots:
    void on_pushButtonEinschalten_clicked();
    void on_pushButtonAusschalten_clicked();
    void zeigeBild();
    void on_NormalAnAus_toggled(bool checked);
    //   void on_verticalSliderHelligkeit_valueChanged(int value);
};


