// Functions of Locations.h

#include <string>
#include <iostream>
#include "locations.h"
#include "Vehicle.h"

string locations::get_name() {
    return name;
}


void locations::set_name(string inputName){
    name = inputName;
}


bool locations::get_clearance(){
    return clearance;
}


void locations::set_clearance(bool inputClearance){
    clearance = inputClearance;
}

int locations::get_ID() const{
    return ID;
}

void locations::set_ID(int inputID) {
    ID = inputID;
}

int locations::get_numInUsage(){
    return numInUsage;
}
void locations::set_numInUsage(int inputNIU){
    numInUsage = inputNIU;
}
int locations::get_numTotalUsage(){
    return numTotalUsage;
}
void locations::set_numTotalUsage(int inputNTU){
    numTotalUsage = inputNTU;
}



void locations::addUsingVehicle(vehicle inputVehicle){
    if(numInUsage == numTotalUsage){cout<< " << INVALID CHOICE >> ";}
    else{
        for(int i = 0; i < numTotalUsage; i++){
            if(usage[i].get_ID() == -1){
                usage[i] = inputVehicle;
                numInUsage++;
            }
        }
    }
}

void locations::removeUsingVehicle(vehicle inputVehicle){
    bool truth = false;
    for(int i = 0; i < numInUsage; i++){
        if(usage[i].get_ID() == inputVehicle.get_ID()){
            usage[i] = vehicle();
            numInUsage--;
            truth = true;
            break;
        }
    }
    if(truth == false){cout << " << INVALID CHOICE >> " << endl;}
}
        

vehicle* locations::get_usage(){
    return usage;
}

void locations::set_usage(vehicle* inputVehicle){
    usage = inputVehicle;
}

locations::locations(){
    numInUsage = 0;
    numTotalUsage = 1;
    clearance = true;
}
