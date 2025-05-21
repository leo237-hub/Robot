#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "include/simulation/feuer.h"
#include "include/roboter.h"
#include "include/Hauptdisplay/Hauptdisplay.h"

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

private slots:
    void on_pushButtonEinschalten_clicked();
    void on_pushButtonAusschalten_clicked();
    void on_verticalSliderHelligkeit_valueChanged(int value);

};
#endif // MAINWINDOW_H
