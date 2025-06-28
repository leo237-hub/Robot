QT += core widgets testlib

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

# Include paths for new structure
INCLUDEPATH += $$PWD/../../app/include \
               $$PWD/../../app/include/simulation

# Test files
SOURCES += test_position.cpp \
           ../../app/source/simulation/position.cpp

HEADERS += test_position.h \
           ../../app/include/simulation/position.h

TARGET = test_position