// Class runway functions

#include <iostream>
#include <string>
#include "locations.h"
#include "runway.h"
#include "Vehicle.h"

runway::runway(){
    lightsOn = false;
}

using namespace std;
bool runway::get_runwayLights(){
    return lightsOn;
}
void runway::set_runwayLights(bool inputLights){
    lightsOn = inputLights;
}
