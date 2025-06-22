TEMPLATE = subdirs
SUBDIRS += \
    ../app\
    ../unitTests

unitTests.depends = app
CONFIG += ordered
