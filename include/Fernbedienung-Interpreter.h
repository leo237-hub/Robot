#pragma once
#include <stdbool.h>
#include <string>
#include <knopf.h>
#include <set>

using namespace std;
class Fernbedienung_interpreter {
public:
    Knopf  Knoepfe[6];
    Knopf *  leseKnoepfe();
    bool schickSignal(Knopf& knopf);
};
