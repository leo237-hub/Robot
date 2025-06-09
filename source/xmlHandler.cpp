#include "xmlHandler.h"
#include <QFile>
#include <QDomDocument>
#include <vector>
#include "feuer.h"
#include "simulationElement.h"
#include "simulation.h"
#include <QColor>
#include <QBrush>
#include <QFileInfo>
using namespace std;



/*
Die xmlHandler-Klasse ist dafür verantwortlich, Simulationsdaten aus einer XML-Datei zu laden.
Sie liest die XML-Datei, parst die Daten und füllt das Simulation-Objekt mit den relevanten Informationen.
Der Rückgabewert gibt an, ob das Laden erfolgreich war oder nicht.
*/
void xmlHandler::ladeSteine(QDomNodeList steineKnoten, Simulation& simulation) {
    for(auto i = 0; i < steineKnoten.count(); ++i) {
        QDomElement stoneElement = steineKnoten.at(i).toElement();
        if (!stoneElement.isNull()) {
            float x = stoneElement.attribute("x").toFloat();
            float y = stoneElement.attribute("y").toFloat();
            float r = stoneElement.attribute("r").toFloat();
            // Create a new Position object and add it to the simulation
            simulationElement * newStone = new simulationElement(x, y, Qt::black, true, r);
            simulation.addiereSteineUmgebung(newStone);
        }
    }
}
void xmlHandler::ladeFeuers(QDomNodeList feuerKnoten,Simulation& simulation) {
    for(auto i = 0; i < feuerKnoten.count(); ++i) {
        QDomElement fireElement = feuerKnoten.at(i).toElement();
        if (!fireElement.isNull()) {
            float x = fireElement.attribute("x").toFloat();
            float y = fireElement.attribute("y").toFloat();
            float r = fireElement.attribute("r").toFloat();
            float temperature = fireElement.attribute("temperature").toFloat();
            // Create a new Fire object and add it to the simulation
            Feuer* newFire = new Feuer(x, y,Qt::red, false,r,temperature);
            simulation.addiereFeuerUmgebung(newFire);
        }

    }
  
}
bool xmlHandler::ladeXmlSimulation(const QString& filePath, Simulation& simulation) {
    vector<Feuer> Feuers;
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly)) return false;

    QDomDocument doc;
    if (!doc.setContent(&file)) return false;
    QDomNodeList feuerKnoten = doc.elementsByTagName("feuer");
    QDomNodeList steineKnoten = doc.elementsByTagName("stein");
    ladeFeuers(feuerKnoten, simulation);
    ladeSteine(steineKnoten, simulation);



return true;
}
