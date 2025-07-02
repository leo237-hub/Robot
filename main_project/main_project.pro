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
    ../unitTests/unit_test_wassersensor/unit_test_wassersensor.pro \
    ../unitTests/unit_test_gassensor/unit_test_gassensor.pro \
    ../unitTests/unit_test_lampe/unit_test_lampe.pro \
    ../unitTests/unit_test_paketfach/unit_test_paketfach.pro \
    ../unitTests/unit_test_knopf/unit_test_knopf.pro \
    ../unitTests/unit_test_gpssensor/unit_test_gpssensor.pro \
    ../unitTests/unit_test_aktoren/unit_test_aktoren.pro \
    ../unitTests/unit_test_FernbedienungInterpreter/unit_test_fernbedienunginterpreter.pro \
    ../unitTests/unit_test_Fernbedienung/unit_test_fernbedienung.pro \
    ../unitTests/unit_test_Lautsprecher/unit_test_lautsprecher.pro \
    ../unitTests/unit_test_joystick2/unit_test_joystick2.pro \
    ../unitTests/unit_test_SignalWandler/unit_test_signalwandler.pro \
    ../unitTests/unit_test_selfcheck/unit_test_selfcheck.pro \
    ../unitTests/unit_test_MittelWerter/unit_test_mittelwerter.pro

unitTests.depends = app
CONFIG += ordered
