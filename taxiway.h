// Class taxiway - based from locations

#include <iostream>
#include <string>
#include "locations.h"
#include "runway.h"
#include "Vehicle.h"

using namespace std;

#ifndef TAXIWAY_H
#define TAXIWAY_H


class taxiway : public locations{
    protected:
        int numConTaxiway; // num connecting runways (active)
        int numTotalTaxiway; // num total runways (single)
    public:
        
        runway* connectingRunway = new runway[numTotalUsage]; // this entire function is for inialising the airpot

        runway* get_connectingRunway();
        void addConnectingRunway(runway inputRunway);
        void removeConnectingRunway(runway inputRunway);

};

#endif

