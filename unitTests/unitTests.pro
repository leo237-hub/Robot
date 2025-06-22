
QT += core widgets testlib xml



CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../include \
               ../include/Hauptdisplay \
               ../include/sensor \
               ../include/simulation

SOURCES += mainTests.cpp \
           ../source/aktoren.cpp \
           ../source/antenne.cpp \
           ../source/BewegungsRoboter.cpp \
           ../source/dc-SingnalInterpreter.cpp \
           ../source/dcmotor.cpp \
           ../source/drehmotor.cpp \
           ../source/feuer.cpp \
           ../source/hauptdisplay.cpp \
           ../source/lampe.cpp \
           ../source/paketfach.cpp \
           ../source/position.cpp \
           ../source/roboter.cpp \
           ../source/selfcheck.cpp \
           ../source/simulation.cpp \
           ../source/simulationElement.cpp \
           ../source/SimulationRoboter.cpp \
           ../source/xmlHandler.cpp

HEADERS += ../include/aktoren.h \
           ../include/antenne.h \
           ../include/BewegungsRoboter.h \
           ../include/Dc-SignalInterpreter.h \
           ../include/dcmotor.h \
           ../include/DreheSignalinterpreter.h \
           ../include/Fernbedienung-Interpreter.h \
           ../include/Fernbedienung.h \
           ../include/joystick.h \
           ../include/joystick2.h \
           ../include/knopf.h \
           ../include/lampe.h \
           ../include/paketfach.h \
           ../include/ReturnHome.h \
           ../include/roboter.h \
           ../include/selfcheck.h \
           ../include/Sensors.h \
           ../include/SignalTyp.h \
           ../include/SignalWandler.h \
           ../include/Hauptdisplay/Hauptdisplay.h \
           ../include/Hauptdisplay/Lautsprecher.h \
           ../include/Hauptdisplay/NormalKamera.h \
           ../include/Hauptdisplay/SensorDisplay.h \
           ../include/Hauptdisplay/Waermekamera.h \
           ../include/Hauptdisplay/WaermeKameraDisplay.h \
           ../include/sensor/Feuchtigkeitssensor.h \
           ../include/sensor/Gassensor.h \
           ../include/sensor/GpsSensor.h \
           ../include/sensor/Kettesensor.h \
           ../include/sensor/Lidarsensor.h \
           ../include/sensor/TemperaturSensor.h \
           ../include/sensor/Wassersensor.h \
           ../include/simulation/feuer.h \
           ../include/simulation/position.h \
           ../include/simulation/simulation.h \
           ../include/simulation/simulationElement.h \
           ../include/simulation/SimulationRoboter.h \
           ../include/simulation/xmlHandler.h


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
