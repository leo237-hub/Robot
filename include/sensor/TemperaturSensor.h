#pragma once

class TemperaturSensor {
private:
    float maxTemperatur;
    float minTemperatur;
    float letzteMessung;

public:
    TemperaturSensor(float minTemp, float maxTemp);
    float temperatureMessen(float T_wert);
    void alarmWennNichtNormal() const;
};

