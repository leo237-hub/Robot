#include "Dc-SignalInterpreter.h"
#include "SignalTyp.h"
#include <string>

signaltyp Dc_SignalInterpreter::EingabeInterpretieren(const std::string & Eingabe) {
    if (Eingabe == "w") {
        return signaltyp::Vorvaerts;
    } else if (Eingabe == "s") {
        return signaltyp::Rueckwaerts;
    } else if (Eingabe == "a") {
        return signaltyp::Links;
    } else if (Eingabe == "d") {
        return signaltyp::Rechts;
    } else if (Eingabe == ",") {
        return signaltyp::DrehenLinks;
    } else if (Eingabe == ".") {
        return signaltyp::DrehenRechts;
    } else {
        return signaltyp::keine;
    }
}
