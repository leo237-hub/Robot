#pragma once
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QTimer>
#include <QMap>

class LEDPanel : public QWidget {
    Q_OBJECT

public:
    explicit LEDPanel(QWidget *parent = nullptr);
    ~LEDPanel();

    // LED Steuerungsmethoden
    void setzeRoboterStatus(bool aktiv);
    void setzeMotorStatus(bool aktiv);
    void setzeDrehmotorStatus(bool aktiv);
    void setzeKameraStatus(bool aktiv);
    void setzeWaermeKameraStatus(bool aktiv);
    void setzeGPSStatus(bool aktiv);
    void setzeTemperaturSensorStatus(bool aktiv);

private:
    void erstelleLEDs();
    void aktualisiereLED(QLabel* led, bool aktiv);
    
    // LED Widgets
    QLabel* roboterLED;
    QLabel* motorLED;
    QLabel* drehmotorLED;
    QLabel* kameraLED;
    QLabel* waermeKameraLED;
    QLabel* gpsLED;
    QLabel* temperaturSensorLED;
    
    // Layout
    QVBoxLayout* hauptLayout;
    QGridLayout* ledLayout;
    
    // LED Zustände
    QMap<QLabel*, bool> ledZustaende;
}; 