QT += core testlib

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

# Include paths
INCLUDEPATH += $$PWD/../../app/include \
               $$PWD/../../app/include/Hauptdisplay

# Test files
SOURCES += test_waermekamera.cpp

HEADERS += test_waermekamera.h

# Source files under test
SOURCES += ../../app/source/Waermekamera.cpp

HEADERS += ../../app/include/Hauptdisplay/Waermekamera.h

TARGET = test_waermekamera