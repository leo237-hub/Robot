#include "WaermekameraDisplay.h"
#include <QImage>
#include <QPixmap>
#include <QDebug>


WaermekameraDisplay::WaermekameraDisplay(QLabel* anzeigeLabel, QObject* parent)
    : QObject(parent), label(anzeigeLabel) {}

void WaermekameraDisplay::waermeBildAnzeigen(uint8_t* data) {
    int breite = 630;
    int hoehe = 480;
    QImage image(data, breite, hoehe, QImage:: Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(image);
    label->setPixmap(pixmap);
    label->setScaledContents(true);
    label->update();
}


