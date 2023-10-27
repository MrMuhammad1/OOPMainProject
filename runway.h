// Class runway - based from locations

#include <iostream>
#include <string>
#include "locations.h"
#include "Vehicle.h"

using namespace std;

#ifndef RUNWAY_H
#define RUNWAY_H


class runway : public locations{
    protected:
        bool lightsOn;
    public:
        runway();

        bool get_runwayLights();
        void set_runwayLights(bool inputLights);

};

#endif

