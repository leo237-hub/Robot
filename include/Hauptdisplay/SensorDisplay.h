#pragma once
using namespace std;
class SensorDisplay {

private:

    string SensorDaten;
    //boolean IfKameraLive;
public:
    // Konstruktoren
    SensorDisplay();
    // Destruktor
    virtual ~ SensorDisplay();

    // Kopierkonstruktor und Zuweisungsoperator
    //MyClass(const MyClass& other); // Kopierkonstruktor
    //MyClass& operator=(const MyClass& other); // Zuweisungsoperator

    // Methoden
    void kameraLiveStarten() const;

    void kAmeraLiveStoppen() const;

    void sensorInformationenAnzeigen() const;

    void gesamteDarstellungAktualisieren() const;

    // Getter und Setter nach Bedarf
    //int getValue() const;
    //void setValue(int value);


};

