QT += core widgets testlib

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

# Include paths for new structure
INCLUDEPATH += $$PWD/../../app/include \
               $$PWD/../../app/include/grafik \
               $$PWD/../../app/include/Hauptdisplay

# Test files
SOURCES += test_waermekameradisplay.cpp \
           ../../app/source/grafik/WaermeKameraDisplay.cpp

HEADERS += test_waermekameradisplay.h \
           ../../app/include/Hauptdisplay/WaermekameraDisplay.h

TARGET = test_waermekameradisplay