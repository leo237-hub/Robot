#pragma once

class Kettensensor {
private:
    int AnzahlSchritte;

public:
    Kettensensor(int initialSchritte = 0);
    int HoleSchritte() const;
    void SchrittHinzufuegen(int schritte);
};





