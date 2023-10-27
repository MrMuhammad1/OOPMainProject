// Class taxiway functions

#include <iostream>
#include <string>
#include "locations.h"
#include "runway.h"
#include "taxiway.h"
//#include "Vehicle.h"

using namespace std;

runway* taxiway::get_connectingRunway(){
    return connectingRunway;
}

void taxiway::addConnectingRunway(runway inputRunway){
    if(numInUsage == numTotalTaxiway){cout<< " << INVALID CHOICE >> ";}
    else{
        for(int i = 0; i < numTotalTaxiway; i++){
            if(connectingRunway[i].get_ID() == -1){
                connectingRunway[i] = inputRunway;
                numConTaxiway++;
            }
        }
    }
}

void taxiway::removeConnectingRunway(runway inputRunway){
    bool truth = false;
    for(int i = 0; i < numConTaxiway; i++){
        if(connectingRunway[i].get_ID() == inputRunway.get_ID()){
            connectingRunway[i] = runway();
            numConTaxiway--;
            truth = true;
            break;
        }
    }
    if(truth == false){cout << " << INVALID CHOICE >> " << endl;}
}

