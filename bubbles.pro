QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    source/aktoren.cpp \
    source/antenne.cpp \
    source/dcmotor.cpp \
    source/drehmotor.cpp \
    source/lampe.cpp \
    source/paketfach.cpp \
    source/roboter.cpp \
    source/selfcheck.cpp \
    source/feuer.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    include/Dc-SignalInterpreter.h \
    include/DreheSignalinterpreter.h \
    include/Fernbedienung-Interpreter.h \
    include/Fernbedienung.h \
    include/Hauptdisplay/Hauptdisplay.h \
    include/Hauptdisplay/Lautsprecher.h \
    include/Hauptdisplay/NormalKamera.h \
    include/Hauptdisplay/SensorDisplay.h \
    include/Hauptdisplay/WärmeKameraDisplay.h \
    include/Hauptdisplay/Wärmekamera.h \
    include/ReturnHome.h \
    include/Sensors.h \
    include/SignalWandler.h \
    include/drehmotor.h \
    include/joystick.h \
    include/joystick2.h \
    include/knopf.h \
    include/paketfach.h \
    include/roboter.h \
    include/sensor/Feuchtigkeitssensor.h \
    include/sensor/Gassensor.h \
    include/sensor/GpsSensor.h \
    include/sensor/Kettesensor.h \
    include/sensor/Lidarsensor.h \
    include/sensor/TemperaturSensor.h \
    include/sensor/Wassersensor.h \
    include/drehmotor.h \
    include/selfcheck.h \
    include/antenne.h \
    include/lampe.h \
    include/aktoren.h \
    include/antenne.h \
    include/dcmotor.h \
    include/Kettesensor.h \
    include/feuer.h \
    mainwindow.h


FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
