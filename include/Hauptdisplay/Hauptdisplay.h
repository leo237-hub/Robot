#pragma once
#include <cstdint>
#include <string>
using namespace std;


class HauptDisplay {
private:
    int helligkeit;
    uint8_t bild;
    string aufloesung;
    bool istAn;
public:
    HauptDisplay();
    virtual ~HauptDisplay();

    void einschalten();
    void ausschalten();
    void anzeigeAktualiesieren(uint8_t neuesBild) ;
    void helligkeitAnpassen(int neueHelligkeit);
    bool isEingeschaltet() const ;
};
