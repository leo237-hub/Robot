#include "xmlHandler.h"
#include <QFile>
#include <QDomDocument>
#include <QDebug>
#include <vector>
#include "feuer.h"
#include "simulation.h"
using namespace std;



/*
Die xmlHandler-Klasse ist dafür verantwortlich, Simulationsdaten aus einer XML-Datei zu laden.
Sie liest die XML-Datei, parst die Daten und füllt das Simulation-Objekt mit den relevanten Informationen.
Der Rückgabewert gibt an, ob das Laden erfolgreich war oder nicht.
*/


bool xmlHandler::ladeXmlSimulation(const QString& filePath, Simulation& simulation) {
    qDebug() << "Loading XML simulation from:" << filePath;
    vector<Feuer> Feuers;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) return false;
    QDomDocument doc;
    if (!doc.setContent(&file)) return false;
    QDomNodeList fireNodes = doc.elementsByTagName("fire");

    for(auto i = 0; i < fireNodes.count(); ++i) {
        QDomElement fireElement = fireNodes.at(i).toElement();
        if (!fireElement.isNull()) {
            float x = fireElement.attribute("x").toFloat();
            float y = fireElement.attribute("y").toFloat();
            float temperature = fireElement.attribute("temperature").toFloat();
            // Create a new Fire object and add it to the simulation
            Feuer* newFire = new Feuer(x, y, 20,temperature);
            simulation.addiereFeuerUmgebung(newFire);
        }

}
return true;
}
