QT += core testlib

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

# Include paths
INCLUDEPATH += $$PWD/../../app/include

# Test files
SOURCES += test_dc_signalinterpreter.cpp

HEADERS += test_dc_signalinterpreter.h

# Source files under test
SOURCES += ../../app/source/dc-SingnalInterpreter.cpp

HEADERS += ../../app/include/Dc-SignalInterpreter.h \
           ../../app/include/SignalTyp.h

TARGET = unit_test_dc_signalinterpreter