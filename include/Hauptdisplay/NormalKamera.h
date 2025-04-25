#ifndef NORMALEKAMERA_H
#define NORMALEKAMERA_H
  
// Hier können Sie notwendige Standardbibliotheken einfügen  
#include <iostream> 
using namespace std; 
  
// Weitere notwendige Includes hier  
  
// Beginn der Klassendefinition  
class NormalKamera {  

private:   
int NummerID;
int Auflösung;
byte bild;
public:  

    // Kopierkonstruktor und Zuweisungsoperator  
    //MyClass(const MyClass& other); // Kopierkonstruktor  
    //MyClass& operator=(const MyClass& other); // Zuweisungsoperator  
  
    // Methoden  
    byte* VideoAufnehmen(byte bild) const;            // soll const sein? was ist mit zeiger

    void AnzeigeAktualiesieren(byte* bild) const;            // soll const sein?

    byte*  FotoMachen(byte bild) const;               // soll const sein?

    int DatenSchicken(byte bild);

    // Getter und Setter nach Bedarf  
    //int getValue() const;  
    //void setValue(int value);  
};  
  
#endif //NORMALEKAMERA_H