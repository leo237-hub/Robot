#pragma once
#include "simulation.h"
#include "feuer.h"
class xmlHandler {
public:
    xmlHandler() = default;
    ~xmlHandler() = default;

    // Method to load simulation data from an XML file
    bool ladeXmlSimulation(const QString& filePath, Simulation& simulation);
};
