#pragma once
#include <iostream>

class WaermekameraDisplay {

private:
    float WaermeBild;
    float MaximaleTemperatur;
    float MinimaleTemperatur;
public:
    WaermekameraDisplay();
    virtual ~WaermekameraDisplay();

    void waermeBildAnzeigen() const;
    void bildQualitätAnpassen() const;

};

