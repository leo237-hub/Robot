QT += core widgets testlib

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

# Include paths
INCLUDEPATH += $$PWD/../../app/include \
               $$PWD/../../app/include/simulation

# Test files
SOURCES += test_feuer.cpp

HEADERS += test_feuer.h

# Source files under test
SOURCES += ../../app/source/feuer.cpp \
           ../../app/source/simulationElement.cpp \
           ../../app/source/position.cpp

HEADERS += ../../app/include/simulation/feuer.h \
           ../../app/include/simulation/simulationElement.h \
           ../../app/include/simulation/position.h

TARGET = test_feuer