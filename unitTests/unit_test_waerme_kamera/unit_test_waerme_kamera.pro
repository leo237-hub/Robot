QT += core testlib

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

# Include paths for new structure
INCLUDEPATH += $$PWD/../../app/include \
               $$PWD/../../app/include/simulation \
               $$PWD/../../app/include/Hauptdisplay \
               $$PWD/../../app/ \
               $$PWD/../../app/include/logik

# Test files
SOURCES += test_waermekamera.cpp \
           ../../app/source/logik/WaermeKamera.cpp

HEADERS += test_waermekamera.h \
           ../../app/include/logik/Waermekamera.h

TARGET = test_waerme_kamera