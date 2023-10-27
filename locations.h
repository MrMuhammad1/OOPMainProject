// Class locations - base of Terminal gate, taxiway and runway

#include <iostream>
#include <string>

#include "Vehicle.h"

using namespace std;

#ifndef LOCATIONS_H
#define LOCATIONS_H


class locations{
    protected:
        int ID;
        string name;
        bool clearance;
        int numInUsage;
        int numTotalUsage;
    public:

        locations();

        vehicle* usage = new vehicle[numTotalUsage];

        virtual int get_ID() const;
        virtual void set_ID(int inputID);

        virtual string get_name();
        virtual void set_name(string inputName);
        virtual bool get_clearance();
        virtual void set_clearance(bool inputClearance);
        virtual int get_numInUsage();
        virtual void set_numInUsage(int inputNIU);
        virtual int get_numTotalUsage();
        virtual void set_numTotalUsage(int inputNTU);

        virtual void addUsingVehicle(vehicle inputVehicle);
        virtual void removeUsingVehicle(vehicle inputVehicle);
        virtual vehicle* get_usage();
        virtual void set_usage(vehicle* inputVehicle);

};

#endif

