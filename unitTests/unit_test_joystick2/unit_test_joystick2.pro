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

SOURCES += test_joystick2.cpp \
           ../../app/source/logik/joystick2.cpp \
           ../../app/source/logik/DreheSignalinterpreter.cpp \
           ../../app/source/logik/drehmotor.cpp \
           ../../app/source/logik/aktoren.cpp
HEADERS += test_joystick2.h

TARGET = test_joystick2 