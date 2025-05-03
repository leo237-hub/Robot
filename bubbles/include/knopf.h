#pragma once
#include <stdbool.h>
#include <string>


using namespace std;
class Knopf {
private:
    bool status;
    string knopfID;
public:
    Knopf(bool status , string ID);
    bool holeStatus();
    string holeID();
};
