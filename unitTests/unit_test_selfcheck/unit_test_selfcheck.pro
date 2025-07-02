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

# Test files
SOURCES += test_selfcheck.cpp \
           ../../app/source/logik/selfcheck.cpp \
           ../../app/source/logik/TemperaturSensor.cpp \
           ../../app/source/logik/Lidarsensor.cpp \
           ../../app/source/logik/GpsSensor.cpp \
           ../../app/source/logik/Gassensor.cpp \
           ../../app/source/logik/Wassersensor.cpp \
           ../../app/source/logik/Kettensensor.cpp
HEADERS += test_selfcheck.h

TARGET = test_selfcheck 