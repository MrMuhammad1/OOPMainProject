#include "helicopter.h"
#include "InAir.h"
#include <iostream>

int InAir::get_NumOfPlanes()
{
    return NumOfPlane;
}

void InAir::set_NumOfPLanes(int i_NumOfPlanes)
{
i_NumOfPlanes=NumOfPlane;
}

int InAir::get_AirLimit()
{
return AirLimit;
}

void InAir::set_AirLimit(int i_AirLimit)
{
i_AirLimit=AirLimit;
}

void InAir::addVehicleInAir(vehicle inputVehicle){
    if(numInAir == AirLimit){cout<< " << INVALID CHOICE >> ";}
    else{
        for(int i = 0; i < AirLimit; i++){
            if(VehiclesInAir[i].get_ID() == -1){
                VehiclesInAir[i] = inputVehicle;
                numInAir++;
            }
        }
    }
}

void InAir::removeVehicleInAir(vehicle inputVehicle){
    bool truth = false;
    for(int i = 0; i < numInAir; i++){
        if(VehiclesInAir[i].get_ID() == inputVehicle.get_ID()){
            VehiclesInAir[i] = vehicle();
            numInAir--;
            truth = true;
            break;
        }
    }
    if(truth == false){cout << " << INVALID CHOICE >> " << endl;}
}
        

vehicle* InAir::get_VehiclesInAir(){
    return VehiclesInAir;
}
