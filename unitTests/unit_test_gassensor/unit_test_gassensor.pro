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
SOURCES += test_gassensor.cpp \
           ../../app/source/logik/Gassensor.cpp

HEADERS += test_gassensor.h \
           ../../app/include/logik/Gassensor.h

TARGET = test_gassensor 