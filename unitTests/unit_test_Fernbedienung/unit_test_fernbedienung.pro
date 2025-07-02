QT += core widgets testlib

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

# Include paths
INCLUDEPATH += $$PWD/../../app/include \
               $$PWD/../../app/include/logik \
               $$PWD/../../app/include/simulation \
               $$PWD/../../app/include/grafik \
               $$PWD/../../app/include/Hauptdisplay

# Test files e dipendenze
SOURCES += test_fernbedienung.cpp \
           ../../app/source/logik/Fernbedienung.cpp \
           ../../app/source/logik/joystick.cpp \
           ../../app/source/logik/joystick2.cpp \
           ../../app/source/logik/SignalWandler.cpp \
           ../../app/source/logik/FernbedienungInterpreter.cpp \
           ../../app/source/logik/knopf.cpp \
           ../../app/source/logik/Hauptdisplay.cpp \
           ../../app/source/logik/dc-SingnalInterpreter.cpp \
           ../../app/source/logik/dcmotor.cpp \
           ../../app/source/logik/lampe.cpp \
           ../../app/source/logik/lautsprecher.cpp \
           ../../app/source/logik/Kettensensor.cpp \
           ../../app/source/logik/TemperaturSensor.cpp \
           ../../app/source/logik/Lidarsensor.cpp \
           ../../app/source/logik/GpsSensor.cpp \
           ../../app/source/logik/Gassensor.cpp \
           ../../app/source/logik/Wassersensor.cpp \
           ../../app/source/logik/DreheSignalinterpreter.cpp \
           ../../app/source/logik/BewegungsRoboter.cpp \
           ../../app/source/logik/paketfach.cpp \
           ../../app/source/logik/aktoren.cpp \
           ../../app/source/logik/drehmotor.cpp
HEADERS += test_fernbedienung.h

TARGET = test_fernbedienung 