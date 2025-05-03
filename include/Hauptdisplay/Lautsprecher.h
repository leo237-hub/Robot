#ifndef LAUTSPRECHER_H  
#define LAUTSPRECHER_H    
  
// Hier können Sie notwendige Standardbibliotheken einfügen  
#include <iostream> 
 
  
// Weitere notwendige Includes hier  
  
// Beginn der Klassendefinition  
class Lautsprecher  { // Vererbung von Aktoren 

private:  
// Membervariablen  
int Lautstärke;
bool Starus; //bolean ist nicht definiert
float TonFrequenz;

  
    // Weitere Hilfsmethoden oder Membervariablen  
public:  
    // Konstruktoren  
    Lautsprecher(); // Standardkonstruktor  
    // Destruktor  
    virtual ~Lautsprecher();  
  

    // Methoden  
    void SpracheAusgeben() const; // Beispiel für eine Methode  
    void LautStärkeAnpassen() const;

};  
  
#endif // LAUTSPRECHER_H    