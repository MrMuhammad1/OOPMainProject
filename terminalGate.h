#ifndef TERMINALGATE_H
#define TERMINALGATE_H

#include <iostream>
#include <string>
#include "locations.h"
#include "Vehicle.h"

using namespace std;

class terminalGate : public locations {
protected:
    int gateType;

public:
    int get_gateType();
    void set_gateType(int inputGateType);
};

#endif
