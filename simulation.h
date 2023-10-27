// Example SimClass

#include <iostream>
#include <string>
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

#ifndef SIMULATION_H
#define SIMULATION_H


class simulation{
    protected:
        int ID;
        string lastInput;
        
        // Clock stuff to keep track of time
        double initialClock;
        double clock;
        
        int numRunways;
        int numTotalRunways;
        int numTaxiways;
        int numTotalTaxiways;
        int numTerminalGates;
        int numTotalTerminalGates;
        int numHangers;
        int numTotalHangers;

        int numPlanes;
        int numTotalPlanes;
        int numHelicopters;
        int numTotalHelicopters;

        // -- Actually interesting variables --
        int ObjcNum; // (ID) keeps track of total objects (planes and Helicopters)

        // bool arrays for which locations have clearance
        bool* terminalClearance;
        bool* taxiwayClearance;
        bool* runwayClearance;

        // 
        int planesInAir;
        int helicoptersInAir;



    public:

        simulation();

        InAir* allInAir = new InAir[1];

        runway* allRunways = new runway[numTotalRunways]; // stores all runways
        taxiway* allTaxiways = new taxiway[numTotalTaxiways]; // stores all taxiways
        terminalGate* allTerminalGates = new terminalGate[numTotalTerminalGates]; // stores all terminal gates
        hanger* allHangers = new hanger[numTotalHangers]; // stores all hangers
        
        vehicle* allPlanes = new vehicle[numTotalPlanes]; // stores all planes
        vehicle* allHelicopters = new vehicle[numTotalHelicopters]; // stores all helicopters

        vehicle* allInAirPlanes = new vehicle[numTotalPlanes]; // stores all planes in the air
        vehicle* allInAirHelicopters = new vehicle[numTotalHelicopters]; // stores all helicopters in the air


        void newPlane(); // creates a new plane
        void removePlane(vehicle inputVehicle); // removes a plane from the airport's range
        vehicle* activePlanes(); // returns all active planes
        
        void newHelicopter(); // creats new helicopter
        void removeHelicopter(vehicle inputVehicle); // removes a helicopter
        vehicle* activeHelicopters(); // returns all active helicopters


        // Simulation Functions

        // -- Location Clearance Functions --
        // lists all true / false statements for the numTotal of each location type
        void terminalClearanceCheck(); 
        void taxiwayClearanceCheck();
        void runwayClearanceCheck();

        // -- InAir -- 
        // Function to count and store the vehicles by type found in the InAir class
        void inAirPlanes();
        void inAirHelicopters();

        // -- Land / TakeOff Functions --
        // Use if statement to see if plane / helicopter is in InAir class
        // selects the plane with the lowest ID
        // used clearance functions to see if anything is unclear for use
        void landPlane();
        void takeOffPlane(Plane inputPlane);

        void landHeli(); 
        void takeOffHeli(Helicopter inputHelicopter);



        











        //void SaveState(); // saves current simulation          // commented due to time
        //void OpenState(); // opens previous simulation

        



};



#endif