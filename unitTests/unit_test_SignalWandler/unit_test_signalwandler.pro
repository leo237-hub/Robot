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

SOURCES += test_signalwandler.cpp \
           ../../app/source/logik/SignalWandler.cpp \
           ../../app/source/logik/Lidarsensor.cpp \
           ../../app/source/logik/BewegungsRoboter.cpp \
           ../../app/source/logik/paketfach.cpp \
           ../../app/source/logik/lampe.cpp \
           ../../app/source/logik/lautsprecher.cpp \
           ../../app/source/logik/dcmotor.cpp \
           ../../app/source/logik/DreheSignalinterpreter.cpp \
           ../../app/source/logik/aktoren.cpp \
           ../../app/source/logik/drehmotor.cpp
HEADERS += test_signalwandler.h

TARGET = test_signalwandler 