#pragma once
#include "qobject.h"
#include "qtmetamacros.h"
#include <QAudioOutput>
#include <QMediaPlayer>

class Lautsprecher: public QObject  {
    Q_OBJECT
private:
    int lautstaerke;
    float tonFrequenz;
    bool status;
    QMediaPlayer* player = nullptr;
    QAudioOutput* audioOutput = nullptr;

public:
    explicit Lautsprecher(QObject *parent = nullptr);
    virtual ~Lautsprecher();

    bool sSchalten();
    void stoppen();
    void spracheAusgeben();
    void lautStaerkeAnpassen(int neueLautstaerke);
    void setStatus(bool status);
};

