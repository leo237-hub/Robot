#pragma once
#include "simulation.h"
#include "feuer.h"
#include <QDomDocument>


class xmlHandler {
private:
    void ladeFeuers(QDomNodeList feuerKnoten, Simulation& simulation);
    void ladeSteine(QDomNodeList steineKnoten, Simulation& simulation);
public:
    xmlHandler() = default;
    ~xmlHandler() = default;

    // Method to load simulation data from an XML file
    bool ladeXmlSimulation(const QString& filePath, Simulation& simulation);

};
