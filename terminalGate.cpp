// Class terminalGate functions

#include <iostream>
#include <string>
#include "locations.h"
#include "terminalGate.h"
#include "Vehicle.h"

using namespace std;
int terminalGate::get_gateType(){
    return gateType;
}
void terminalGate::set_gateType(int inputGateType){
    gateType = inputGateType;
}
