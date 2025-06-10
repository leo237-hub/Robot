#pragma once
#include <cstdint>
#include <string>
using namespace std;


class HauptDisplay {
private:
    int helligkeit;
    uint8_t bild;  // uint8_t statt byte
    string aufloesung;
    bool istAn;  // ob die Oberfläche an oder aus
public:
    HauptDisplay();
    // Constructor
    virtual ~HauptDisplay();      // Destructor

    void einschalten();          // Display anschalten
    void ausschalten();          // Display ausschalten
    void anzeigeAktualiesieren(uint8_t neuesBild) ;
    void helligkeitAnpassen(int neueHelligkeit);
    bool isEingeschaltet() const ;
};
