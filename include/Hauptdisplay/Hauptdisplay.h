#pragma once
// Hier können Sie notwendige Standardbibliotheken einfügen
#include <cstdint>
#include <string>
using namespace std;

// Weitere notwendige Includes hier

// Beginn der Klassendefinition
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
