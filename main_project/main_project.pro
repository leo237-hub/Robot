TEMPLATE = subdirs
SUBDIRS += \
    ../app\
    ../unitTests/unit_tests_position \
    ../unitTests/unit_tests_simelement \
    ../unitTests/unit_tests_feuer \
    ../unitTests/unit_test_dc_signalinterpreter \

unitTests.depends = app
CONFIG += ordered
