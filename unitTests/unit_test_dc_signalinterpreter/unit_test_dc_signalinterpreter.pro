QT += core testlib

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

# Include paths for new structure
INCLUDEPATH += $$PWD/../../app/include \
                $$PWD/../../app/include/logik

# Test files
SOURCES += test_dc_signalinterpreter.cpp \
           ../../app/source/logik/dc-SingnalInterpreter.cpp

HEADERS += test_dc_signalinterpreter.h \
           ../../app/include/logik/Dc-SignalInterpreter.h \
           ../../app/include/logik/SignalTyp.h

TARGET = unit_test_dc_signalinterpreter