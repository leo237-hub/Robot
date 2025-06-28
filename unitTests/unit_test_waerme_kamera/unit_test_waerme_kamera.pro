QT += core testlib

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

# Include paths for new structure
INCLUDEPATH += $$PWD/../../app/include \
               $$PWD/../../app/include/simulation \
               $$PWD/../../app/include/Hauptdisplay \
               $$PWD/../../app/

# Test files
SOURCES += test_waermekamera.cpp \
           ../../app/source/simulation/WaermeKamera.cpp

HEADERS += test_waermekamera.h \
           ../../app/include/Hauptdisplay/Waermekamera.h

TARGET = test_waerme_kamera