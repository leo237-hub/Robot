#include "joystick.h"
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>

joystick::joystick() 
    : winkel(0.0f)
    , intensitaet(0.0f) {
}

void joystick::Fahren() {
    // Bewegungslogik basierend auf Winkel und Intensität
    // Hier würde die Kommunikation mit den Motoren erfolgen
    interpretiereBewegung();
    // Weitergabe an Dc_SignalInterpreter für Motorsteuerung
}

void joystick::Halten() {
    intensitaet = 0.0f;
    // Stoppt die Bewegung
}

void joystick::setzeWinkel(float neuerWinkel) {
    if (neuerWinkel >= 0.0f && neuerWinkel <= 360.0f) {
        winkel = neuerWinkel;
    }
}

void joystick::setzeIntensitaet(float neueIntensitaet) {
    if (neueIntensitaet >= 0.0f && neueIntensitaet <= 100.0f) {
        intensitaet = neueIntensitaet;
    }
}

float joystick::getWinkel() const {
    return winkel;
}

float joystick::getIntensitaet() const {
    return intensitaet;
}

/*
Interpretiert die Joystick-Eingabe und wandelt sie in ein Bewegungssignal um
Rückgabe: signaltyp für die entsprechende Bewegungsrichtung
*/
signaltyp joystick::interpretiereBewegung() const {
    if (intensitaet < 10.0f) {
        return signaltyp::keine; // Keine Bewegung bei zu geringer Intensität
    }
    
    // Winkel in Bewegungsrichtung umwandeln
    if (winkel >= 315.0f || winkel < 45.0f) {
        return signaltyp::Vorvaerts;
    } else if (winkel >= 45.0f && winkel < 135.0f) {
        return signaltyp::Rechts;
    } else if (winkel >= 135.0f && winkel < 225.0f) {
        return signaltyp::Rueckwaerts;
    } else if (winkel >= 225.0f && winkel < 315.0f) {
        return signaltyp::Links;
    }
    
    return signaltyp::keine;
}

/*
Verarbeitet Joystick-Eingaben (x, y Koordinaten) und wandelt sie in Winkel und Intensität um
Parameter: x - X-Koordinate (-1.0 bis 1.0), y - Y-Koordinate (-1.0 bis 1.0)
*/
void joystick::verarbeiteJoystickEingabe(float x, float y) {
    // Intensität aus x,y Koordinaten berechnen
    intensitaet = sqrt(x*x + y*y) * 100.0f;
    if (intensitaet > 100.0f) intensitaet = 100.0f;
    
    // Winkel aus x,y Koordinaten berechnen
    if (intensitaet > 10.0f) {
        winkel = atan2(y, x) * 180.0f / M_PI;
        if (winkel < 0) winkel += 360.0f;
    } else {
        winkel = 0.0f;
    }
} 