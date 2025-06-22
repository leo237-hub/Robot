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
        QDomElement steinElement = steineKnoten.at(i).toElement();
        if (!steinElement.isNull()) {
            float x = steinElement.attribute("x").toFloat();
            float y = steinElement.attribute("y").toFloat();
            float r = steinElement.attribute("r").toFloat();
            simulationElement * neuerStein = new simulationElement(x, y, Qt::black, true, r);
            simulation.addiereSteineUmgebung(neuerStein);
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
            Feuer* newFire = new Feuer(x, y,Qt::red, false,r,temperature);
            simulation.addiereFeuerUmgebung(newFire);
        }

    }

}
void xmlHandler::ladePersonen(QDomNodeList personKnoten, Simulation& simulation) {
    for(auto i = 0; i < personKnoten.count(); ++i) {
        QDomElement personElement = personKnoten.at(i).toElement();
        if (!personElement.isNull()) {
            float x = personElement.attribute("x").toFloat();
            float y = personElement.attribute("y").toFloat();
            float r = personElement.attribute("r").toFloat();
            simulationElement * neuePerson = new simulationElement(x, y, Qt::white, true, r);
            simulation.addierePersonUmgebung(neuePerson);
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
    QDomNodeList personKnoten = doc.elementsByTagName("person");
    ladePersonen(personKnoten,simulation);
    ladeFeuers(feuerKnoten, simulation);
    ladeSteine(steineKnoten, simulation);

    return true;
}
