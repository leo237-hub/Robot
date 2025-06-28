#include "knopf.h"


Knopf::Knopf() 
    : status(false)
    , knopfID("") {
}

Knopf::Knopf(bool status, const std::string& id) 
    : status(status)
    , knopfID(id) {
}


bool Knopf::holeStatus() const {
    return status;
}


std::string Knopf::holeID() const {
    return knopfID;
}

void Knopf::setzeStatus(bool neuerStatus) {
    status = neuerStatus;
}