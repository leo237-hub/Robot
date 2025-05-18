//
// Created by irina on 21.04.25.
//

#ifndef APPEND_C_TEMPERATURSENSOR_H
#define APPEND_C_TEMPERATURSENSOR_H

class TemperaturSensor {
private:
    float maxTemperatur;
    float minTemperatur;
    float letzteMessung;

public:
    // Constructor
    TemperaturSensor(float minTemp, float maxTemp);

    // Simulate measuring temperature and store the value
    float temperatureMessen(float T_wert);

    // Check if temperature is outside the normal range and trigger alarm
    void alarmWennNichtNormal() const;
};

#endif //APPEND_C_TEMPERATURSENSOR_H
