TEMPLATE = subdirs
SUBDIRS += \
    ../app\
    ../unitTests/unit_tests_position \
    ../unitTests/unit_tests_simelement \
    ../unitTests/unit_tests_feuer

unitTests.depends = app
CONFIG += ordered
