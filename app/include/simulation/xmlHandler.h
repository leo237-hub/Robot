#pragma once
#include "simulation.h"
#include "feuer.h"
#include "gasSimulationElement.h"
#include "wasserSimulationElement.h"
#include <QDomDocument>


class xmlHandler {
private:
    void ladeFeuers(QDomNodeList feuerKnoten, Simulation& simulation);
    void ladeGasQuellen(QDomNodeList gasQuellenKnoten, Simulation& simulation);
    void ladeWasserQuellen(QDomNodeList wasserQuellenKnoten, Simulation& simulation);
    void ladeSteine(QDomNodeList steineKnoten, Simulation& simulation);
    void ladePersonen(QDomNodeList personKnoten,Simulation& simulation);
public:
    xmlHandler() = default;
    ~xmlHandler() = default;


    bool ladeXmlSimulation(const QString& filePath, Simulation& simulation);

};
