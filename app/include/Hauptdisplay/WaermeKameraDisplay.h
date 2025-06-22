#pragma once

#include <QObject>
#include <QLabel>
#include <cstdint>

class WaermekameraDisplay : public QObject {
    Q_OBJECT

public:
    explicit WaermekameraDisplay(QLabel* anzeigeLabel, QObject* parent = nullptr);
    void waermeBildAnzeigen(uint8_t* data);

private:
    QLabel* label;
};
