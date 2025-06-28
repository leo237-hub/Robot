QT += core widgets testlib

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

# Include paths
INCLUDEPATH += $$PWD/../../app/include \
               $$PWD/../../app/include/logik \
               $$PWD/../../app/include/simulation \
               $$PWD/../../app/include/grafik \
               $$PWD/../../app/include/Hauptdisplay \
               $$PWD/../../app/include/sensor

# Test files
SOURCES += test_feuer.cpp \
           ../../app/source/simulation/feuer.cpp \
           ../../app/source/simulation/simulationElement.cpp \
           ../../app/source/simulation/position.cpp

HEADERS += test_feuer.h \
           ../../app/include/simulation/feuer.h

TARGET = test_feuer