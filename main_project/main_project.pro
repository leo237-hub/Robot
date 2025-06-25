TEMPLATE = subdirs
SUBDIRS += \
    ../app\
    ../unitTests/unit_test_bewegungRoboter/test_bewegungsroboter.pro \
    ../unitTests/unit_test_waerme_kamera \
    ../unitTests/unit_test_waermekamera_display/test_waermekameradisplay.pro \
    ../unitTests/unit_tests_position \
    ../unitTests/unit_tests_simelement \
    ../unitTests/unit_tests_feuer \
    ../unitTests/unit_test_dc_signalinterpreter \


unitTests.depends = app
CONFIG += ordered
