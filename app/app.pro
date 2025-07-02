QT       += core gui
QT += xml


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -Wall -Wextra -Wpedantic


CONFIG += c++17
CONFIG += moc
CONFIG += console
CONFIG -= bubbles


SOURCES += \
    source/logik/BewegungsRoboter.cpp \
    source/logik/dcmotor.cpp \
    source/logik/drehmotor.cpp \
    source/logik/aktoren.cpp \
    source/logik/lampe.cpp \
    source/logik/lautsprecher.cpp \
    source/logik/antenne.cpp \
    source/logik/knopf.cpp \
    source/logik/joystick.cpp \
    source/logik/joystick2.cpp \
    source/logik/paketfach.cpp \
    source/logik/Fernbedienung.cpp \
    source/logik/FernbedienungInterpreter.cpp \
    source/logik/dc-SingnalInterpreter.cpp \
    source/logik/DreheSignalinterpreter.cpp \
    source/logik/SignalWandler.cpp \
    source/logik/selfcheck.cpp \
    source/logik/NormalKamera.cpp \
    source/logik/GpsSensor.cpp \
    source/logik/TemperaturSensor.cpp \
    source/logik/Gassensor.cpp \
    source/logik/Wassersensor.cpp \
    source/logik/hauptdisplay.cpp \
    source/logik/WaermeKamera.cpp \
    source/logik/Lidarsensor.cpp \
    source/logik/Kettensensor.cpp \
    source/simulation/BewegungsSimulation.cpp \
    source/simulation/simulation.cpp \
    source/simulation/SimulationRoboter.cpp \
    source/simulation/feuer.cpp \
    source/simulation/gasSimulationElement.cpp \
    source/simulation/wasserSimulationElement.cpp \
    source/simulation/simulationElement.cpp \
    source/simulation/xmlHandler.cpp \
    source/simulation/position.cpp \
    source/grafik/GraphischesRoboter.cpp \
    source/grafik/RoboterVisualization.cpp \
    source/grafik/mainwindow.cpp \
    source/grafik/main.cpp \
    source/grafik/WaermeKameraDisplay.cpp \
    source/grafik/LEDPanel.cpp

HEADERS += \
    include/logik/BewegungsRoboter.h \
    include/logik/dcmotor.h \
    include/logik/drehmotor.h \
    include/logik/aktoren.h \
    include/logik/lampe.h \
    include/logik/lautsprecher.h \
    include/logik/antenne.h \
    include/logik/knopf.h \
    include/logik/joystick.h \
    include/logik/joystick2.h \
    include/logik/paketfach.h \
    include/logik/Fernbedienung.h \
    include/logik/FernbedienungInterpreter.h \
    include/logik/Dc-SignalInterpreter.h \
    include/logik/DreheSignalinterpreter.h \
    include/logik/SignalWandler.h \
    include/logik/selfcheck.h \
    include/logik/ReturnHome.h \
    include/logik/SignalTyp.h \
    include/logik/NormalKamera.h \
    include/logik/GpsSensor.h \
    include/logik/Kettesensor.h \
    include/logik/Lidarsensor.h \
    include/logik/TemperaturSensor.h \
    include/logik/Wassersensor.h \
    include/logik/Hauptdisplay.h \
    include/logik/Waermekamera.h \
    include/logik/Lautsprecher.h \
    include/logik/SensorDisplay.h \
    include/simulation/BewegungsSimulation.h \
    include/simulation/SimulationRoboter.h \
    include/simulation/feuer.h \
    include/simulation/gasSimulationElement.h \
    include/simulation/wasserSimulationElement.h \
    include/simulation/position.h \
    include/simulation/simulation.h \
    include/simulation/xmlHandler.h \
    include/simulation/simulationElement.h \
    include/grafik/GraphischesRoboter.h \
    include/grafik/RoboterVisualization.h \
    include/grafik/mainwindow.h \
    include/grafik/LEDPanel.h \
    include/grafik/WaermeKameraDisplay.h

# Absolute include paths - makes it easy to use absolute includes in code
INCLUDEPATH += $$PWD/include
INCLUDEPATH += $$PWD/include/logik
INCLUDEPATH += $$PWD/include/simulation
INCLUDEPATH += $$PWD/include/grafik

RESOURCES += \
    resources/resources.qrc

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
