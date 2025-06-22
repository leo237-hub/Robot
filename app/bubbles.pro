QT       += core gui
QT += xml


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -Wall -Wextra -Wpedantic

TEMPLATE = subdirs
SUBDIRS =  unitTests

CONFIG += c++17
CONFIG += moc
CONFIG += console
CONFIG -= bubbles


SOURCES += \
    source/BewegungsRoboter.cpp \
    source/NormalKamera.cpp \
    source/SimulationRoboter.cpp \
    source/WaermeKameraDisplay.cpp \
    source/WearmeKamera.cpp \
    source/aktoren.cpp \
    source/antenne.cpp \
    source/dc-SingnalInterpreter.cpp \
    source/dcmotor.cpp \
    source/drehmotor.cpp \
    source/hauptdisplay.cpp \
    source/lampe.cpp \
    source/paketfach.cpp \
    source/roboter.cpp \
    source/selfcheck.cpp \
    source/feuer.cpp \
    source/simulation.cpp \
    source/position.cpp \
    source/xmlHandler.cpp \
    source/TemperaturSensor.cpp\
    source/simulationElement.cpp \
    source/main.cpp \
    source/mainwindow.cpp

HEADERS += \
    include/BewegungsRoboter.h \
    include/Dc-SignalInterpreter.h \
    include/DreheSignalinterpreter.h \
    include/Fernbedienung-Interpreter.h \
    include/Fernbedienung.h \
    include/Hauptdisplay/Hauptdisplay.h \
    include/Hauptdisplay/Lautsprecher.h \
    include/Hauptdisplay/NormalKamera.h \
    include/Hauptdisplay/SensorDisplay.h \
    include/Hauptdisplay/WaermeKameraDisplay.h \
    include/Hauptdisplay/Waermekamera.h \
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
    include/simulation/SimulationRoboter.h \
    include/simulation/feuer.h \
    include/simulation/position.h \
    include/simulation/simulation.h \
    include/simulation/xmlHandler.h \
    include/simulation/simulationElement.h \
    include/SignalTyp.h \
    include/mainwindow.h
INCLUDEPATH += $$PWD/include/
INCLUDEPATH += $$PWD/include/Hauptdisplay/
INCLUDEPATH += $$PWD/include/sensor/
INCLUDEPATH += $$PWD/include/simulation/

RESOURCES += resources.qrc

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
