// Simulation Function Code

#include <iostream>
#include <string>
#include "simulation.h"
#include "locations.h"
#include "runway.h"
#include "taxiway.h"
#include "terminalGate.h"
#include "hanger.h"
#include "Vehicle.h"
#include "Plane.h"
#include "Helicopter.h"
#include "InAir.h"


using namespace std;

simulation::simulation(){ // default constuctor for ensuring all values are preset correctly
    
    // All of the values below create a simple airport in terms of size
    numTotalHangers = 1;
    numTotalRunways = 1;
    numTotalTaxiways = 5;
    numTotalTerminalGates = 10;

    numTotalHelicopters = 3;
    numTotalPlanes = 11;
    
    // Initialise active values
    numHangers = 0;
    numRunways = 0;
    numTaxiways = 0;
    numTerminalGates = 0;
    numHelicopters = 0;
    numPlanes = 0;
    planesInAir = 0;
    helicoptersInAir = 0;
    
    //initialsing initalClock and clock
    initialClock = time(NULL);
    clock = time(NULL) - initialClock; // time(NULL) + 1 is 1 second in the future

    // Initalising Runways
    for(int i = 0; i < numTotalRunways; i++){ // adding set max runways
        runway allRunways[i]; // default constructor
        allRunways[i].set_ID((i)); // set ID based on for loop
        string tempStr1 = "Runway "; 
        string tempStr2 = tempStr1.append(to_string((i+1))); // Stringing together "Runway 1", "Runway 2", etc.
        allRunways[i].set_name(tempStr2); // Naming Runway
        allRunways[i].set_runwayLights(false); // Setting Runways lights to false (off)
    }

    // Initalising Taxiways
    for(int i = 0; i < numTotalTaxiways; i++){ // adding set max taxiways
        taxiway allTaxiways[i]; // default constructor
        allTaxiways[i].set_ID((i)); // set ID based on for loop
        string tempStr1 = "Taxiway "; 
        string tempStr2 = tempStr1.append(to_string((i+1))); // Stringing together "Taxiway 1", "Taxiway 2", etc.
        allTaxiways[i].set_name(tempStr2); // Naming Taxiway
    }

    // Initalising TerminalGates
    for(int i = 0; i < numTotalTerminalGates; i++){ // adding set max Terminal Gates
        terminalGate allTerminalGates[i]; // default constructor
        allTerminalGates[i].set_ID((i)); // set ID based on for loop
        string tempStr1 = "Terminal Gate "; 
        string tempStr2 = tempStr1.append(to_string((i+1))); // Stringing together "TerminalGate 1", "TerminalGate 2", etc.
        allTerminalGates[i].set_name(tempStr2); // Naming Runway
    }

    // Initalising Hanger
    for(int i = 0; i < numTotalHangers; i++){ // adding set max hangers
        hanger allHangers[i]; // default constructor
        allHangers[i].set_ID((i)); // set ID based on for loop
        string tempStr1 = "Hanger "; 
        string tempStr2 = tempStr1.append(to_string((i+1))); // Stringing together "Hanger 1", "Hanger 2", etc.
        allHangers[i].set_name(tempStr2); // Naming hanger
    }

}


// Creating a new plane
void simulation::newPlane(){
    if(numPlanes == numTotalPlanes){cout<< "Not Enough Air Space" << endl;}
    else{
        for(int i = 0; i < numTotalPlanes; i++){ // cheacking all possible spaces 
            if(allPlanes[i].get_ID() == -1){ 
                allPlanes[i] = Plane();
                allPlanes[i].set_ID(ObjcNum);
                allPlanes[i].set_vehicleType(1);
                
                allInAir[0].addVehicleInAir(allPlanes[i]);

                numPlanes++;
                ObjcNum++;
            }
        }
    }
}

// Removing Plane
void simulation::removePlane(vehicle inputVehicle){
    bool truth = false;
    for(int i = 0; i < numPlanes; i++){ // checking all inputted planes
        if(allPlanes[i].get_ID() == inputVehicle.get_ID()){
            allPlanes[i] = vehicle();
            numPlanes--;
            truth = true;
            break;
        }
    }
    if(truth == false){cout << "| Plane Does Not Exist |" << endl;}
}

vehicle* simulation::activePlanes(){
    return allPlanes;
}

// Adding Helicopter
void simulation::newHelicopter(){
    if(numHelicopters == numTotalHelicopters){cout<< "Not Enought Air Space" << endl;}
    else{
        for(int i = 0; i < numTotalHelicopters; i++){
            if(allHelicopters[i].get_ID() == -1){
                allHelicopters[i] = Helicopter();
                allHelicopters[i].set_ID(ObjcNum);
                allHelicopters[i].set_vehicleType(2);
                numHelicopters++;
                ObjcNum++;
            }
        }
    }
}

// Removing Helicopter
void simulation::removeHelicopter(vehicle inputVehicle){
    bool truth = false;
    for(int i = 0; i < numHelicopters; i++){
        if(allHelicopters[i].get_ID() == inputVehicle.get_ID()){
            allHelicopters[i] = vehicle();
            numHelicopters--;
            truth = true;
            break;
        }
    }
    if(truth == false){cout << "| Helicopter Does Not Exist |" << endl;}
}

vehicle* simulation::activeHelicopters(){
    return allHelicopters;
}

// The following 3 functions use a for loop to look though every location indavidually for where there is clearance
void simulation::terminalClearanceCheck(){
    for(int i = 0; i < numTotalTerminalGates; i++){
        terminalClearance[i] = allTerminalGates[i].get_clearance();
    }
}
void simulation::taxiwayClearanceCheck(){
    for(int i = 0; i < numTotalTaxiways; i++){
        taxiwayClearance[i] = allTaxiways[i].get_clearance();
    }
}
void simulation::runwayClearanceCheck(){
    for(int i = 0; i < numTotalRunways; i++){
        runwayClearance[i] = allRunways[i].get_clearance();
    }
}

// The folling 2 functions count and store the planes / helicopters in the InAir class seperately
void simulation::inAirPlanes(){
    vehicle* VehiclesInAir = allInAir[0].get_VehiclesInAir();
    allInAirPlanes = new vehicle[numTotalPlanes];
    planesInAir = 0;

    for(int i = 0; i < numTotalPlanes; i++){
        if(VehiclesInAir[i].get_vehicleType() == 1){
            allInAirPlanes[planesInAir] = VehiclesInAir[i];
            planesInAir++;
        }
    }
}
void simulation::inAirHelicopters(){
    vehicle* VehiclesInAir = allInAir[0].get_VehiclesInAir();
    allInAirHelicopters = new vehicle[numTotalHelicopters];
    helicoptersInAir = 0;

    for(int i = 0; i < numTotalPlanes; i++){
        if(VehiclesInAir[i].get_vehicleType() == 2){
            allInAirHelicopters[helicoptersInAir] = VehiclesInAir[i];
            helicoptersInAir++;
        }
    }
}

// The following function checks for a clear runway, then lands on said runway
// It then checks for both a clear terminal and taxiway, and travels through the taxiway to the terminal gate.
void simulation::landPlane(){  
    vehicle PlaneToLand;

    for(int i = 0; i < numTotalRunways; i++){
        if(allRunways[i].get_clearance() == true){
            int locate = 0;
            int minVal = INT_MAX;
            for(int j = 0; j < planesInAir; i++){
                if(allInAirPlanes[j].get_ID() < minVal ){
                    minVal = allInAirPlanes[j].get_ID();
                    PlaneToLand = allInAirPlanes[j];
                    locate = j;
                }
            }

            if(minVal != INT_MAX){
                cout << PlaneToLand.get_Name() << " lands on " << allRunways[i].get_name() << endl;
                allRunways[i].addUsingVehicle(PlaneToLand);
                allInAirPlanes[locate] = vehicle();
            }

            break;
        }
        
    }
    for(int i = 0; i < numTotalTaxiways; i++){
        for(int j = 0; j < numTotalTerminalGates; j++){
            if(allTaxiways[i].get_clearance() == true){
                if(allTerminalGates[j].get_clearance() == true && allTerminalGates[j].get_gateType() == 0){
                    cout << PlaneToLand.get_Name() << " uses " << allTaxiways[i].get_name() << " to unload at " << allTerminalGates[j].get_name() << endl;
                    allTerminalGates[j].addUsingVehicle(PlaneToLand);
                    return;
                }
            }
        }
    }

}

// The following function is similar to landPlane, in that it checks for clearance across taxiway and runway, but the function also removes it from the terminal gate
// Once the plane takes off from the runway, then plane is removed from the simulation
void simulation::takeOffPlane(Plane inputPlane){
    for(int i = 0; i < numTotalTerminalGates; i++){
        if(allTerminalGates[i].get_usage()->get_ID() == inputPlane.get_ID()){
            cout << inputPlane.get_Name() << " has left " << allTerminalGates[i].get_name() << endl;
            allTerminalGates[i].removeUsingVehicle(inputPlane);
            break;
        }
    }

    for(int i = 0; i < numTotalTaxiways; i++){
        for(int j = 0; j < numTotalRunways; j++){
            if(allTaxiways[i].get_clearance() == true){
                if(allRunways[j].get_clearance() == true){
                    cout << inputPlane.get_Name() << " uses " << allTaxiways[i].get_name() << " to take off from " << allRunways[j].get_name() << endl;
                    removePlane(inputPlane);
                    return;
                }
            }
        }
    }

}

// Similar to landPlane, except because helicopters don't use runways and taxiways, the helicopter checks for clearance on helipad terminal gate types and lands if possible 
void simulation::landHeli(){
    for(int i = 0; i < numTotalTerminalGates; i++){
        if(allTerminalGates[i].get_clearance() == true && allTerminalGates[i].get_gateType() == 1){
            int locate = 0;
            int minVal = INT_MAX;
            vehicle HeliToLand;
            for(int j = 0; j < helicoptersInAir; i++){
                if(allInAirHelicopters[j].get_ID() < minVal ){
                    minVal = allInAirHelicopters[j].get_ID();
                    HeliToLand = allInAirHelicopters[j];
                    locate = j;
                    break;
                }
            }

            if(minVal != INT_MAX){
                cout << HeliToLand.get_Name() << " will be landing on " << allTerminalGates[i].get_name() << endl;
                allTerminalGates[i].addUsingVehicle(HeliToLand);
                allInAirHelicopters[locate] = vehicle();
                return;
            }
        }
    }

}
void simulation::takeOffHeli(Helicopter inputHelicopter){
    for(int i = 0; i < numTotalTerminalGates; i++){
        if(allTerminalGates[i].get_usage()->get_ID() == inputHelicopter.get_ID()){
            cout << inputHelicopter.get_Name() << " takes off from " << allTerminalGates[i].get_name() << endl;
            allTerminalGates[i].removeUsingVehicle(inputHelicopter);
            removeHelicopter(inputHelicopter);
            return;
        }
    }
}







































//void simulation::SaveState(){} // Commented due to time.
//void simulation::OpenState(){}
