#include<QDebug>
#include "Dc-SignalInterpreter.h"

signaltyp Dc_SignalInterpreter::EingabeInterpretieren(const std::string &Eingabe){
    qDebug() << "Eingabe erhalten:" << QString::fromStdString(Eingabe);
    if(Eingabe == "w" || Eingabe == "W")
        return signaltyp::Vorvaerts;
    else if(Eingabe == "s" || Eingabe == "S")
        return signaltyp::Rueckwaerts;
    else if(Eingabe == "a" || Eingabe == "A")
        return signaltyp::Links;
    else if(Eingabe == "d" || Eingabe == "D")
        return signaltyp::Rechts;
    else
        return signaltyp::keine;
}
