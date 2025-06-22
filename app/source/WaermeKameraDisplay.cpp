#include "WaermekameraDisplay.h"
#include <QImage>
#include <QPixmap>
#include <QDebug>


WaermekameraDisplay::WaermekameraDisplay(QLabel* anzeigeLabel, QObject* parent)
    : QObject(parent), label(anzeigeLabel) {}

void WaermekameraDisplay::waermeBildAnzeigen(uint8_t* data) {
    int width = 630;
    int hight = 480;
    QImage image(data, width, hight, QImage:: Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(image);
    label->setPixmap(pixmap);
    label->setScaledContents(true);
    label->update();
}


