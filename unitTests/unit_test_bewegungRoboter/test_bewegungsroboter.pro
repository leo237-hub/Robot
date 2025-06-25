QT += core testlib gui widgets 

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

# Include paths
INCLUDEPATH += $$PWD/../../app/include \
                $$PWD/../../app/include/Hauptdisplay \
                $$PWD/../../app/include/sensor

# Test files
SOURCES += test_bewegungsroboter.cpp

HEADERS += test_bewegungsroboter.h

# Source files under test
SOURCES += ../../app/source/BewegungsRoboter.cpp \
           ../../app/source/dcmotor.cpp \
           ../../app/source/aktoren.cpp

HEADERS += ../../app/include/BewegungsRoboter.h \
           ../../app/include/dcmotor.h \
           ../../app/include/aktoren.h \
           ../../app/include/SignalTyp.h

TARGET = test_bewegungsroboter