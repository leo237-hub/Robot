#ifndef APPEND_C_KETTESENSOR_H
#define APPEND_C_KETTESENSOR_H

class Kettensensor {
private:
    int AnzahlSchritte;

public:
    // Constructor
    Kettensensor(int initialSchritte = 0);

    // Gibt die aktuelle Anzahl an Schritten zurück
    int HoleSchritte() const;

    //Methode zum Erhöhen der Schrittzahl
    void SchrittHinzufuegen(int schritte);
};

#endif //APPEND_C_KETTESENSOR_H
