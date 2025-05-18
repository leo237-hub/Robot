#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*
    TODO: Instanziierung von folgenden Klassen
    1. TemperaturSensor
    2. Simulationsklasse
    3. Bewegung (Amer schreibe hier ganeu was du dier einfallen lassen hast)
    4. Display
    5. Joystick
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}
