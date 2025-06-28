#include "joystick2.h"
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>

joystick2::joystick2() 
    : winkel(0.0f)
    , intensitaet(0.0f) {
}

void joystick2::WinkelAnpassen(float neuerWinkel) {
    setzeWinkel(neuerWinkel);
    // Rotationslogik basierend auf Winkel und Intensität
    // Hier würde die Kommunikation mit dem Drehmotor erfolgen
    interpreter.verarbeiteRotation(winkel, intensitaet);
}

void joystick2::setzeWinkel(float neuerWinkel) {
    if (neuerWinkel >= 0.0f && neuerWinkel <= 360.0f) {
        winkel = neuerWinkel;
    }
}

void joystick2::setzeIntensitaet(float neueIntensitaet) {
    if (neueIntensitaet >= 0.0f && neueIntensitaet <= 100.0f) {
        intensitaet = neueIntensitaet;
    }
}

float joystick2::getWinkel() const {
    return winkel;
}

float joystick2::getIntensitaet() const {
    return intensitaet;
}

/*
Verarbeitet Joystick-Eingaben (x, y Koordinaten) und wandelt sie in Winkel und Intensität um
Parameter: x - X-Koordinate (-1.0 bis 1.0), y - Y-Koordinate (-1.0 bis 1.0)
*/
void joystick2::verarbeiteJoystickEingabe(float x, float y) {
    // Intensität aus x,y Koordinaten berechnen
    intensitaet = sqrt(x*x + y*y) * 100.0f;
    if (intensitaet > 100.0f) intensitaet = 100.0f;
    
    // Winkel aus x,y Koordinaten berechnen (nur horizontale Bewegung für Rotation)
    if (intensitaet > 10.0f) {
        winkel = atan2(y, x) * 180.0f / M_PI;
        if (winkel < 0) winkel += 360.0f;
    } else {
        winkel = 0.0f;
    }
    
    // Kommuniziere mit DreheSignalInterpreter
    interpreter.verarbeiteRotation(winkel, intensitaet);
}

/*
Gibt den aktuellen Rotationswinkel für die Kopfbewegung zurück
Rückgabe: Winkel in Grad für die Rotation
*/
float joystick2::getRotationsWinkel() const {
    return winkel;
} 