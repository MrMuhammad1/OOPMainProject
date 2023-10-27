#include <iostream>
#include <string>

#ifndef VEHICLE_H
#define VEHICLE_H

using namespace std;

class vehicle{ 
    protected:

    int ID;
    string Name;
    string Company;
    int VehicleType; // 0 = non flying, 1 = plane, 2 = helicopter
    
    int PassengerSize;
    double TimeOfUse;
    double Fuel;
    
    public:

    vehicle(string name, double fuel);
    vehicle() = default;
    
    int get_ID();
    void set_ID(int inputID);

    string get_Name();
    void set_Name(string);

    void set_Fuel(double NewFuel);
    double get_Fuel();

    string get_Company();
    void set_Company(string NewCompany);

    int get_vehicleType();
    void set_vehicleType(int inputVehicleType);

    int get_PassengerSize();
    void set_PassengerSize(int NewPassengerSize);

    double get_TimeOfUse();
    void set_TimeofUse(double NewTimeOfUse);
    
    virtual ~vehicle();

};

#endif