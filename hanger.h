// Class hanger

#include <iostream>
#include <string>

#include "Vehicle.h"

using namespace std;

#ifndef HANGER_H
#define HANGER_H


class hanger{
    protected:
        int ID;
        string name;
        double* refuelingLeft;
        int* estRefuelingTimeLeft;
        int numPlanesInside;
        int numInHanger;
        int numTotalHanger;
        
    public:

        int get_ID();
        void set_ID(int inputID);

        string get_name();
        void set_name(string inputName);

        vehicle* planesInside = new vehicle[numTotalHanger];

        vehicle* get_planesInside();
        void addHangerVehicle(vehicle inputVehicle);
        void removeHangerVehicle(vehicle inputVehicle);
        void displayRefuelingLeft();
        void get_numPlanesInside();

        


};

#endif

