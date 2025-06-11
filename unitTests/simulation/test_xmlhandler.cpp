#include "test_xmlhandler.h"

void TestXmlHandler::init()
{
    handler = new xmlHandler();
    simulation = new Simulation();
}

void TestXmlHandler::cleanup()
{
    delete handler;
    delete simulation;
}

/*
Test für das Laden einer validen XML Datei
*/
void TestXmlHandler::testLadeValidesXml()
{
    QString xmlInhalt = erstelleValidesTestXml();
    QTemporaryFile* datei = schreibeXmlInDatei(xmlInhalt);
    
    bool ergebnis = handler->ladeXmlSimulation(datei->fileName(), *simulation);
    
    QVERIFY(ergebnis);
    delete datei;
}

/*
Test für nicht existierende Datei
*/
void TestXmlHandler::testLadeNichtExistierendeDatei()
{
    QString nichtExistierenderPfad = "/nicht/existierender/pfad/datei.xml";
    
    bool ergebnis = handler->ladeXmlSimulation(nichtExistierenderPfad, *simulation);
    
    QVERIFY(!ergebnis);
}

/*
Test für leere Datei
*/
void TestXmlHandler::testLadeLeereDatei()
{
    QTemporaryFile* datei = schreibeXmlInDatei("");
    
    bool ergebnis = handler->ladeXmlSimulation(datei->fileName(), *simulation);
    
    QVERIFY(!ergebnis);
    delete datei;
}

/*
Test für fehlerhaftes XML
*/
void TestXmlHandler::testLadeFehlerhaftesXml()
{
    QString fehlerhaftesXml = erstelleFehlerhaftesXml();
    QTemporaryFile* datei = schreibeXmlInDatei(fehlerhaftesXml);
    
    bool ergebnis = handler->ladeXmlSimulation(datei->fileName(), *simulation);
    
    QVERIFY(!ergebnis);
    delete datei;
}

/*
Test für XML mit Feuer Elementen
*/
void TestXmlHandler::testLadeXmlMitFeuern()
{
    QString xmlMitFeuern = erstelleXmlMitFeuern();
    QTemporaryFile* datei = schreibeXmlInDatei(xmlMitFeuern);
    
    bool ergebnis = handler->ladeXmlSimulation(datei->fileName(), *simulation);
    
    QVERIFY(ergebnis);
    QVERIFY(simulation->gruppeFeuer.size() > 0);
    delete datei;
}

/*
Test für XML mit Stein Elementen
*/
void TestXmlHandler::testLadeXmlMitSteinen()
{
    QString xmlMitSteinen = erstelleXmlMitSteinen();
    QTemporaryFile* datei = schreibeXmlInDatei(xmlMitSteinen);
    
    bool ergebnis = handler->ladeXmlSimulation(datei->fileName(), *simulation);
    
    QVERIFY(ergebnis);
    QVERIFY(simulation->Steine.size() > 0);
    delete datei;
}

/*
Test für XML mit Personen Elementen
*/
void TestXmlHandler::testLadeXmlMitPersonen()
{
    QString xmlMitPersonen = erstelleXmlMitPersonen();
    QTemporaryFile* datei = schreibeXmlInDatei(xmlMitPersonen);
    
    bool ergebnis = handler->ladeXmlSimulation(datei->fileName(), *simulation);
    
    QVERIFY(ergebnis);
    QVERIFY(simulation->Personen.size() > 0);
    delete datei;
}

/*
Test für XML mit allen Elementtypen
*/
void TestXmlHandler::testLadeXmlMitAllenElementen()
{
    QString vollstaendigesXml = erstelleValidesTestXml();
    QTemporaryFile* datei = schreibeXmlInDatei(vollstaendigesXml);
    
    size_t anfaenglicheFeuerAnzahl = simulation->gruppeFeuer.size();
    size_t anfaenglicheSteinAnzahl = simulation->Steine.size();
    size_t anfaenglichePersonAnzahl = simulation->Personen.size();
    
    bool ergebnis = handler->ladeXmlSimulation(datei->fileName(), *simulation);
    
    QVERIFY(ergebnis);
    QVERIFY(simulation->gruppeFeuer.size() >= anfaenglicheFeuerAnzahl);
    QVERIFY(simulation->Steine.size() >= anfaenglicheSteinAnzahl);
    QVERIFY(simulation->Personen.size() >= anfaenglichePersonAnzahl);
    delete datei;
}

/*
Test für XML ohne Elemente
*/
void TestXmlHandler::testLadeXmlOhneElemente()
{
    QString leeresXml = erstelleLeeresXml();
    QTemporaryFile* datei = schreibeXmlInDatei(leeresXml);
    
    bool ergebnis = handler->ladeXmlSimulation(datei->fileName(), *simulation);
    
    QVERIFY(ergebnis);  // Sollte erfolgreich sein, aber keine Elemente hinzufügen
    delete datei;
}

/*
Test für XML mit ungültigem Inhalt
*/
void TestXmlHandler::testLadeXmlMitUngueltigemInhalt()
{
    QString ungueltigerInhalt = "<simulation><ungueltig>test</ungueltig></simulation>";
    QTemporaryFile* datei = schreibeXmlInDatei(ungueltigerInhalt);
    
    bool ergebnis = handler->ladeXmlSimulation(datei->fileName(), *simulation);
    
    // Sollte erfolgreich parsen, aber keine bekannten Elemente hinzufügen
    QVERIFY(ergebnis);
    delete datei;
}

/*
Hilfsmethoden für Test XML Erstellung
*/
QString TestXmlHandler::erstelleValidesTestXml()
{
    return QString(
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<simulation>\n"
        "  <feuers>\n"
        "    <feuer id=\"1\" x=\"10\" y=\"20\" temperature=\"150.0\" r=\"15\"/>\n"
        "    <feuer id=\"2\" x=\"30\" y=\"40\" temperature=\"200.0\" r=\"15\"/>\n"
        "  </feuers>\n"
        "  <steine>\n"
        "    <stein id=\"1\" x=\"50\" y=\"60\" r=\"12\"/>\n"
        "  </steine>\n"
        "  <personen>\n"
        "    <person id=\"1\" x=\"70\" y=\"80\" r=\"12\"/>\n"
        "  </personen>\n"
        "</simulation>"
    );
}

QString TestXmlHandler::erstelleXmlMitFeuern()
{
    return QString(
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<simulation>\n"
        "  <feuers>\n"
        "    <feuer id=\"1\" x=\"5\" y=\"10\" temperature=\"100.0\" r=\"15\"/>\n"
        "    <feuer id=\"2\" x=\"15\" y=\"25\" temperature=\"250.0\" r=\"15\"/>\n"
        "  </feuers>\n"
        "</simulation>"
    );
}

QString TestXmlHandler::erstelleXmlMitSteinen()
{
    return QString(
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<simulation>\n"
        "  <steine>\n"
        "    <stein id=\"1\" x=\"100\" y=\"200\" r=\"12\"/>\n"
        "    <stein id=\"2\" x=\"150\" y=\"250\" r=\"20\"/>\n"
        "  </steine>\n"
        "</simulation>"
    );
}

QString TestXmlHandler::erstelleXmlMitPersonen()
{
    return QString(
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<simulation>\n"
        "  <personen>\n"
        "    <person id=\"1\" x=\"300\" y=\"400\" r=\"12\"/>\n"
        "    <person id=\"2\" x=\"350\" y=\"450\" r=\"12\"/>\n"
        "  </personen>\n"
        "</simulation>"
    );
}

QString TestXmlHandler::erstelleFehlerhaftesXml()
{
    return QString(
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<simulation>\n"
        "  <feuers>\n"
        "    <feuer id=\"1\" x=\"10\" y=\"20\" temperature=\"150.0\"\n"  // Fehlende schließende >
        "  </feuers>\n"
        "  <steine>\n"
        "    <stein id=\"1\" x=\"50\" y=\"60\" r=\"12\"/>\n"
        "  </steine>\n"
        "</simulation>"
    );
}

QString TestXmlHandler::erstelleLeeresXml()
{
    return QString(
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<simulation>\n"
        "  <feuers>\n"
        "  </feuers>\n"
        "  <steine>\n"
        "  </steine>\n"
        "  <personen>\n"
        "  </personen>\n"
        "</simulation>"
    );
}

QTemporaryFile* TestXmlHandler::schreibeXmlInDatei(const QString& xmlInhalt)
{
    QTemporaryFile* datei = new QTemporaryFile();
    datei->open();
    
    QTextStream stream(datei);
    stream << xmlInhalt;
    datei->close();
    
    return datei;
}

