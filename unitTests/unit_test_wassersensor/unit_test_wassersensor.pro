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
SOURCES += test_wassersensor.cpp \
           ../../app/source/logik/Wassersensor.cpp

HEADERS += test_wassersensor.h \
           ../../app/include/logik/Wassersensor.h

TARGET = test_wassersensor 