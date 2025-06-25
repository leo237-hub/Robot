QT += core widgets testlib

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

# Include paths
INCLUDEPATH += $$PWD/../../app/include \
               $$PWD/../../app/include/Hauptdisplay

# Test files
SOURCES += test_waermekameradisplay.cpp

HEADERS += test_waermekameradisplay.h

# Source files under test
SOURCES += ../../app/source/WaermekameraDisplay.cpp

HEADERS += ../../app/include/Hauptdisplay/WaermekameraDisplay.h

TARGET = test_waermekameradisplay