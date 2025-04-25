#ifndef SENSORDISPLAY_H  
#define SENSORDISPLAY_H 
  
// Hier können Sie notwendige Standardbibliotheken einfügen  
#include <iostream> 
using namespace std; 
  
// Weitere notwendige Includes hier  
  
// Beginn der Klassendefinition  
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

    void KAmeraLiveStoppen() const;

    void SensorInformationenAnzeigen() const;

    void GesamteDarstellungAktualisieren() const;

    // Getter und Setter nach Bedarf  
    //int getValue() const;  
    //void setValue(int value);  
  

};  
  
#endif //SENSORDISPLAY_H 