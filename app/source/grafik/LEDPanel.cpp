#include "LEDPanel.h"
#include <QStyle>
#include <QApplication>

LEDPanel::LEDPanel(QWidget *parent)
    : QWidget(parent)
{
    setFixedWidth(150);
    setMinimumHeight(400);
    
    /* Hintergrundfarbe setzen */
    setStyleSheet("QWidget { background-color: #2b2b2b; border: 2px solid #555555; border-radius: 10px; }");
    
    /* Haupt-Layout erstellen */
    hauptLayout = new QVBoxLayout(this);
    hauptLayout->setSpacing(10);
    hauptLayout->setContentsMargins(10, 10, 10, 10);
    
    /* Titel erstellen */
    QLabel* titelLabel = new QLabel("STATUS LED");
    titelLabel->setAlignment(Qt::AlignCenter);
    titelLabel->setStyleSheet("QLabel { color: white; font-weight: bold; font-size: 14px; }");
    hauptLayout->addWidget(titelLabel);
    
    /* LED-Grid erstellen */
    ledLayout = new QGridLayout();
    ledLayout->setSpacing(8);
    hauptLayout->addLayout(ledLayout);
    
    /* LEDs erstellen */
    erstelleLEDs();
    
    /* Stretch hinzufügen um alles nach oben zu drücken */
    hauptLayout->addStretch();
}

LEDPanel::~LEDPanel() {
}

void LEDPanel::erstelleLEDs() {
    /* Roboter LED */
    QLabel* roboterLabel = new QLabel("Roboter");
    roboterLabel->setStyleSheet("QLabel { color: white; font-size: 10px; }");
    roboterLED = new QLabel();
    roboterLED->setFixedSize(20, 20);
    roboterLED->setStyleSheet("QLabel { background-color: #ff0000; border: 2px solid #333333; border-radius: 10px; }");
    ledLayout->addWidget(roboterLabel, 0, 0);
    ledLayout->addWidget(roboterLED, 0, 1);
    
    /* Motor LED */
    QLabel* motorLabel = new QLabel("Motor");
    motorLabel->setStyleSheet("QLabel { color: white; font-size: 10px; }");
    motorLED = new QLabel();
    motorLED->setFixedSize(20, 20);
    motorLED->setStyleSheet("QLabel { background-color: #ff0000; border: 2px solid #333333; border-radius: 10px; }");
    ledLayout->addWidget(motorLabel, 1, 0);
    ledLayout->addWidget(motorLED, 1, 1);
    
    /* Drehmotor LED */
    QLabel* drehmotorLabel = new QLabel("Drehmotor");
    drehmotorLabel->setStyleSheet("QLabel { color: white; font-size: 10px; }");
    drehmotorLED = new QLabel();
    drehmotorLED->setFixedSize(20, 20);
    drehmotorLED->setStyleSheet("QLabel { background-color: #ff0000; border: 2px solid #333333; border-radius: 10px; }");
    ledLayout->addWidget(drehmotorLabel, 2, 0);
    ledLayout->addWidget(drehmotorLED, 2, 1);
    
    /* Kamera LED */
    QLabel* kameraLabel = new QLabel("Kamera");
    kameraLabel->setStyleSheet("QLabel { color: white; font-size: 10px; }");
    kameraLED = new QLabel();
    kameraLED->setFixedSize(20, 20);
    kameraLED->setStyleSheet("QLabel { background-color: #ff0000; border: 2px solid #333333; border-radius: 10px; }");
    ledLayout->addWidget(kameraLabel, 3, 0);
    ledLayout->addWidget(kameraLED, 3, 1);
    
    /* WaermeKamera LED */
    QLabel* waermeKameraLabel = new QLabel("W-Kamera");
    waermeKameraLabel->setStyleSheet("QLabel { color: white; font-size: 10px; }");
    waermeKameraLED = new QLabel();
    waermeKameraLED->setFixedSize(20, 20);
    waermeKameraLED->setStyleSheet("QLabel { background-color: #ff0000; border: 2px solid #333333; border-radius: 10px; }");
    ledLayout->addWidget(waermeKameraLabel, 4, 0);
    ledLayout->addWidget(waermeKameraLED, 4, 1);
    
    /* GPS LED */
    QLabel* gpsLabel = new QLabel("GPS");
    gpsLabel->setStyleSheet("QLabel { color: white; font-size: 10px; }");
    gpsLED = new QLabel();
    gpsLED->setFixedSize(20, 20);
    gpsLED->setStyleSheet("QLabel { background-color: #ff0000; border: 2px solid #333333; border-radius: 10px; }");
    ledLayout->addWidget(gpsLabel, 5, 0);
    ledLayout->addWidget(gpsLED, 5, 1);
    
    /* TemperaturSensor LED */
    QLabel* temperaturLabel = new QLabel("Temp");
    temperaturLabel->setStyleSheet("QLabel { color: white; font-size: 10px; }");
    temperaturSensorLED = new QLabel();
    temperaturSensorLED->setFixedSize(20, 20);
    temperaturSensorLED->setStyleSheet("QLabel { background-color: #ff0000; border: 2px solid #333333; border-radius: 10px; }");
    ledLayout->addWidget(temperaturLabel, 6, 0);
    ledLayout->addWidget(temperaturSensorLED, 6, 1);
    
    /* GasSensor LED */
    QLabel* gasLabel = new QLabel("Gas");
    gasLabel->setStyleSheet("QLabel { color: white; font-size: 10px; }");
    gassensorLED = new QLabel();
    gassensorLED->setFixedSize(20, 20);
    gassensorLED->setStyleSheet("QLabel { background-color: #ff0000; border: 2px solid #333333; border-radius: 10px; }");
    ledLayout->addWidget(gasLabel, 7, 0);
    ledLayout->addWidget(gassensorLED, 7, 1);
    
    /* Wassersensor LED */
    QLabel* wasserLabel = new QLabel("Wasser");
    wasserLabel->setStyleSheet("QLabel { color: white; font-size: 10px; }");
    wassersensorLED = new QLabel();
    wassersensorLED->setFixedSize(20, 20);
    wassersensorLED->setStyleSheet("QLabel { background-color: #ff0000; border: 2px solid #333333; border-radius: 10px; }");
    ledLayout->addWidget(wasserLabel, 8, 0);
    ledLayout->addWidget(wassersensorLED, 8, 1);
    
    /* Alle LEDs als ausgeschaltet initialisieren */
    ledZustaende[roboterLED] = false;
    ledZustaende[motorLED] = false;
    ledZustaende[drehmotorLED] = false;
    ledZustaende[kameraLED] = false;
    ledZustaende[waermeKameraLED] = false;
    ledZustaende[gpsLED] = false;
    ledZustaende[temperaturSensorLED] = false;
    ledZustaende[gassensorLED] = false;
    ledZustaende[wassersensorLED] = false;
}

void LEDPanel::aktualisiereLED(QLabel* led, bool aktiv) {
    if (ledZustaende[led] != aktiv) {
        ledZustaende[led] = aktiv;
        if (aktiv) {
            led->setStyleSheet("QLabel { background-color: #00ff00; border: 2px solid #333333; border-radius: 10px; }");
        } else {
            led->setStyleSheet("QLabel { background-color: #ff0000; border: 2px solid #333333; border-radius: 10px; }");
        }
    }
}

void LEDPanel::setzeRoboterStatus(bool aktiv) {
    aktualisiereLED(roboterLED, aktiv);
}

void LEDPanel::setzeMotorStatus(bool aktiv) {
    aktualisiereLED(motorLED, aktiv);
}

void LEDPanel::setzeDrehmotorStatus(bool aktiv) {
    aktualisiereLED(drehmotorLED, aktiv);
}

void LEDPanel::setzeKameraStatus(bool aktiv) {
    aktualisiereLED(kameraLED, aktiv);
}

void LEDPanel::setzeWaermeKameraStatus(bool aktiv) {
    aktualisiereLED(waermeKameraLED, aktiv);
}

void LEDPanel::setzeGPSStatus(bool aktiv) {
    aktualisiereLED(gpsLED, aktiv);
}

void LEDPanel::setzeTemperaturSensorStatus(bool aktiv) {
    aktualisiereLED(temperaturSensorLED, aktiv);
}

void LEDPanel::setzeGassensorStatus(bool aktiv) {
    aktualisiereLED(gassensorLED, aktiv);
}

void LEDPanel::setzeWassersensorStatus(bool aktiv) {
    aktualisiereLED(wassersensorLED, aktiv);
} 
