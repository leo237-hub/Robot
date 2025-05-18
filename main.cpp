#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QCoreApplication>

#include "include/simulation/feuer.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();
}
