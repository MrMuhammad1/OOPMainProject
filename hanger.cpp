// Functions of Locations.hq

#include <string>
#include <iostream>
#include "hanger.h"
#include "Vehicle.h"

using namespace std;

int hanger::get_ID(){
    return ID;
}

void hanger::set_ID(int inputID){
    ID = inputID;
}

vehicle* hanger::get_planesInside(){ 
    for(int i = 0; i < numPlanesInside; i++){ cout << "Plane [" << i << "] : " << (planesInside[i].get_ID());}; // get ID is temp, until we know what we want
    cout << endl;
}

void hanger::addHangerVehicle(vehicle inputVehicle){           // adds vehicle to hanger's planesInside variable and ++ to numPlanesInside
    if(numInHanger == numTotalHanger){cout<< " << INVALID CHOICE >> ";}
    else{
        for(int i = 0; i < numTotalHanger; i++){
            if(planesInside[i].get_ID() == -1){
                planesInside[i] = inputVehicle;
                numInHanger++;
            }
        }
    }
}

void hanger::removeHangerVehicle(vehicle inputVehicle){           // removes vehicle to hanger's planesInside variable and -- to numPlanesInside
    bool truth = false;
    for(int i = 0; i < numInHanger; i++){
        if(planesInside[i].get_ID() == inputVehicle.get_ID()){
            planesInside[i] = vehicle();
            numInHanger--;
            truth = true;
            break;
        }
    }
    if(truth == false){cout << " << INVALID CHOICE >> " << endl;}
}

void hanger::displayRefuelingLeft(){  // Takes all vehicles in planesInside, checks fuel per plane, and outputs array for each plane refueling left via "refuelingLeft" variable
    for(int i = 0; i < numPlanesInside; i++){
        refuelingLeft[i] = 100 - planesInside[i].get_Fuel();
    }
}

string hanger::get_name(){
    return name;
}

void hanger::set_name(string inputName){
    name = inputName;
}