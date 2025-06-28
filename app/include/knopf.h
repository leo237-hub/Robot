#pragma once
#include <string>

/*
Zweck und Verhalten der Knopf-Klasse:

Zweck: Repräsentation eines einzelnen Knopfes auf der Fernbedienung mit Status und eindeutiger Identifikation.

Verhalten: Die Klasse verwaltet den Zustand (gedrückt/nicht gedrückt) eines Knopfes und speichert seine eindeutige ID. 
Der Status kann abgefragt und geändert werden, um Benutzereingaben zu simulieren oder zu verarbeiten.
*/
class Knopf {
private:
    bool status;
    std::string knopfID;

public:
    Knopf();
    Knopf(bool status, const std::string& id);
    ~Knopf() = default;
    
    bool holeStatus() const;
    std::string holeID() const;
    void setzeStatus(bool neuerStatus);
};