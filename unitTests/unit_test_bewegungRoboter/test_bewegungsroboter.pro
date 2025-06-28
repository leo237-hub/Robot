QT += core testlib gui widgets 

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

# Include paths for new structure
INCLUDEPATH += $$PWD/../../app/include \
                $$PWD/../../app/include/logik \
                $$PWD/../../app/include/simulation \
                $$PWD/../../app/include/grafik \
                $$PWD/../../app/include/Hauptdisplay \
                $$PWD/../../app/include/sensor

# Test files
SOURCES += test_bewegungsroboter.cpp \
           ../../app/source/logik/BewegungsRoboter.cpp \
           ../../app/source/logik/dcmotor.cpp \
           ../../app/source/logik/aktoren.cpp

HEADERS += test_bewegungsroboter.h \
           ../../app/include/logik/BewegungsRoboter.h \
           ../../app/include/logik/dcmotor.h \
           ../../app/include/logik/aktoren.h \
           ../../app/include/logik/SignalTyp.h

TARGET = test_bewegungsroboter