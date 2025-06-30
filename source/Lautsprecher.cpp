#include "Lautsprecher.h"
#include "qdebug.h"
#include <QMediaPlayer>
#include <QCoreApplication>
#include <QAudioOutput>


Lautsprecher::Lautsprecher(QObject *parent) :
   QObject(parent), lautstaerke(50), tonFrequenz(440.0f), status(false){

    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(0.5);
}
Lautsprecher::~Lautsprecher(){}


bool Lautsprecher::sSchalten(){
    status = !status;
    qDebug() << "Lautsprecher wurde geschaltet.";
    return status;
}

void Lautsprecher::spracheAusgeben() {
    if (status) {
        player->setSource(QUrl("qrc:/data/resources/sos-morsecode-31731.mp3"));
        player->play();
        qDebug()<< "Der Lautsprecher gibt Sprache aus.";
    } else {
    qDebug()<< "Der Lautsprecher ist ausgeschaltet.";
        player->stop();
        qDebug()<< "Der Lautsprecher ist ausgeschaltet.";
    }
}

void Lautsprecher::lautStaerkeAnpassen(int neueLautstaerke) {

    if ( neueLautstaerke >= 0 && neueLautstaerke <= 100) {
        lautstaerke = neueLautstaerke;
        qDebug()<< "Die Lautstärke wurde auf " << lautstaerke << " eingestellt.";
    } else {
        qDebug()<< "Ungültige Lautstärke.";
    }
}

void Lautsprecher::setStatus(bool statusValue) {
    status = statusValue;
}

void Lautsprecher::stoppen() {
    if (player) player->stop();
    qDebug() << "Der Lautsprecher hat gestoppt.";
}
