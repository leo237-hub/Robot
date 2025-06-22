
QT += core widgets testlib xml



CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app
INCLUDEPATH += $$PWD/../app/include

INCLUDEPATH += ../app/include \
               ../app/include/Hauptdisplay \
               ../app/include/sensor \
               ../app/include/simulation

SOURCES += mainTests.cpp \
           ../app/source/aktoren.cpp \
           ../app/source/antenne.cpp \
           ../app/source/BewegungsRoboter.cpp \
           ../app/source/dc-SingnalInterpreter.cpp \
           ../app/source/dcmotor.cpp \
           ../app/source/drehmotor.cpp \
           ../app/source/feuer.cpp \
           ../app/source/hauptdisplay.cpp \
           ../app/source/lampe.cpp \
           ../app/source/paketfach.cpp \
           ../app/source/position.cpp \
           ../app/source/roboter.cpp \
           ../app/source/selfcheck.cpp \
           ../app/source/simulation.cpp \
           ../app/source/simulationElement.cpp \
           ../app/source/SimulationRoboter.cpp \
           ../app/source/xmlHandler.cpp

HEADERS += ../app/include/aktoren.h \
           ../app/include/antenne.h \
           ../app/include/BewegungsRoboter.h \
           ../app/include/Dc-SignalInterpreter.h \
           ../app/include/dcmotor.h \
           ../app/include/DreheSignalinterpreter.h \
           ../app/include/Fernbedienung-Interpreter.h \
           ../app/include/Fernbedienung.h \
           ../app/include/joystick.h \
           ../app/include/joystick2.h \
           ../app/include/knopf.h \
           ../app/include/lampe.h \
           ../app/include/paketfach.h \
           ../app/include/ReturnHome.h \
           ../app/include/roboter.h \
           ../app/include/selfcheck.h \
           ../app/include/Sensors.h \
           ../app/include/SignalTyp.h \
           ../app/include/SignalWandler.h \
           ../app/include/Hauptdisplay/Hauptdisplay.h \
           ../app/include/Hauptdisplay/Lautsprecher.h \
           ../app/include/Hauptdisplay/NormalKamera.h \
           ../app/include/Hauptdisplay/SensorDisplay.h \
           ../app/include/Hauptdisplay/Waermekamera.h \
           ../app/include/Hauptdisplay/WaermeKameraDisplay.h \
           ../app/include/sensor/Feuchtigkeitssensor.h \
           ../app/include/sensor/Gassensor.h \
           ../app/include/sensor/GpsSensor.h \
           ../app/include/sensor/Kettesensor.h \
           ../app/include/sensor/Lidarsensor.h \
           ../app/include/sensor/TemperaturSensor.h \
           ../app/include/sensor/Wassersensor.h \
           ../app/include/simulation/feuer.h \
           ../app/include/simulation/position.h \
           ../app/include/simulation/simulation.h \
           ../app/include/simulation/simulationElement.h \
           ../app/include/simulation/SimulationRoboter.h \
           ../app/include/simulation/xmlHandler.h


# Simulation test files
SOURCES += simulation/test_position.cpp \
           simulation/test_simulationelement.cpp \
           simulation/test_feuer.cpp \
           simulation/test_xmlhandler.cpp \
           simulation/test_simulation.cpp

HEADERS += simulation/test_position.h \
           simulation/test_simulationelement.h \
           simulation/test_feuer.h \
           simulation/test_xmlhandler.h \
           simulation/test_simulation.h

TARGET = unitTests
