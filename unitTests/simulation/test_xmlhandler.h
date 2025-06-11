#pragma once
#include <QtTest/QtTest>
#include <QTemporaryFile>
#include <QTextStream>
#include "xmlHandler.h"
#include "simulation.h"

/*
Unit Test für xmlHandler Klasse
Getestet:
- XML Datei erfolgreich laden
- Fehlerhaftes XML behandeln
- Leere XML Dateien
- Nicht existierende Dateien
- Korrekte Erstellung von Simulationselementen
- Verschiedene XML Strukturen
*/

class TestXmlHandler : public QObject
{
    Q_OBJECT
    

private slots:
    void init();
    void cleanup();
    
    void testLadeValidesXml();
    void testLadeNichtExistierendeDatei();
    void testLadeLeereDatei();
    void testLadeFehlerhaftesXml();
    
    void testLadeXmlMitFeuern();
    void testLadeXmlMitSteinen();
    void testLadeXmlMitPersonen();
    void testLadeXmlMitAllenElementen();
    
    void testLadeXmlOhneElemente();
    void testLadeXmlMitUngueltigemInhalt();

private:
    xmlHandler* handler;
    Simulation* simulation;
    
    QString erstelleValidesTestXml();
    QString erstelleXmlMitFeuern();
    QString erstelleXmlMitSteinen();
    QString erstelleXmlMitPersonen();
    QString erstelleFehlerhaftesXml();
    QString erstelleLeeresXml();
    
    QTemporaryFile* schreibeXmlInDatei(const QString& xmlInhalt);
};