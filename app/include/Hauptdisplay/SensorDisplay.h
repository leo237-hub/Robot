#pragma once
#include<string>
using namespace std;
class SensorDisplay {

private:
    string SensorDaten;

public:
    SensorDisplay();
    virtual ~ SensorDisplay();
    void kameraLiveStarten() const;
    void kameraLiveStoppen() const;
    void sensorInformationenAnzeigen() const;
    void gesamteDarstellungAktualisieren() const;
};

