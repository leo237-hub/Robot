#include"Waermekamera.h"
#include "qdebug.h"
#include "qlogging.h"
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>


WaermeKamera::WaermeKamera():aktiv(false){ }
WaermeKamera::~ WaermeKamera(){ }

bool WaermeKamera::wSchalten(){
    aktiv=!aktiv;
    return aktiv;
    qDebug() << "WaermeKamera wurde geschaltet.";
}
uint8_t* WaermeKamera::fotoMachen(uint8_t) const {
    const int breite = 640;
    const int hoehe = 480;
    const int groesse = breite * hoehe * 3;

    if (breite <= 0 || hoehe <= 0) return nullptr;

    uint8_t* data = new uint8_t[groesse];

    int numHotSpots = 3 + (rand() % 5); 
    std::vector<std::pair<int, int>> hotSpots;
    
    for (int i = 0; i < numHotSpots; i++) {
        hotSpots.push_back({rand() % breite, rand() % hoehe});
    }

    for (int y = 0; y < hoehe; y++) {
        for (int x = 0; x < breite; x++) {
            int index = (y * breite + x) * 3;
            
            float temperature = 20.0f + (rand() % 10) * 0.1f; // 20-21°C base
            
            for (const auto& spot : hotSpots) {
                float distance = sqrt((x - spot.first) * (x - spot.first) + 
                                    (y - spot.second) * (y - spot.second));
                if (distance < 50) {
                    float intensity = (50 - distance) / 50.0f;
                    temperature += intensity * (60.0f + (rand() % 40)); // Fino a 100°C
                }
            }
            
            uint8_t r, g, b;
            
            if (temperature < 30) {
                r = 0;
                g = 0;
                b = 255 - (temperature - 20) * 25;
            } else if (temperature < 60) {
                r = (temperature - 30) * 8;
                g = 255;
                b = 0;
            } else {
                r = 255;
                g = 255 - (temperature - 60) * 6;
                b = 0;
            }
            
            r = std::min(255, std::max(0, (int)r));
            g = std::min(255, std::max(0, (int)g));
            b = std::min(255, std::max(0, (int)b));
            
            data[index] = r;
            data[index + 1] = g;
            data[index + 2] = b;
        }
    }

    return data;
}
float WaermeKamera::temperaturLesen(){
    return 0;
}
uint8_t* WaermeKamera::videoAufnehmen(uint8_t bild [[maybe_unused]]) const {
    return 0;
} 