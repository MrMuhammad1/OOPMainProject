#include "Vehicle.h"
using namespace std;

string vehicle::get_Name()
{
    return Name;

}

void vehicle::set_Name(string inname)
{
Name = inname;
}

void vehicle::set_Fuel(double NewFuel)
{
Fuel = NewFuel;

}

double vehicle::get_Fuel()
{
    return Fuel;
}

string vehicle::get_Company()
{
    return Company;
}

void vehicle::set_Company(string NewCompany)
{
    Company = NewCompany;
}

int vehicle::get_PassengerSize()
{
    return PassengerSize;
}

void vehicle::set_PassengerSize(int NewPassengerSize)
{
PassengerSize=NewPassengerSize;
}

double vehicle::get_TimeOfUse()
{
    return TimeOfUse;
}

void vehicle::set_TimeofUse(double NewTimeOfUse)
{
    TimeOfUse=NewTimeOfUse;
}

vehicle::vehicle(string inname, double NewFuel)
{
Name = inname;
Fuel = NewFuel;
}

int vehicle::get_vehicleType(){
    return VehicleType;
}

void vehicle::set_vehicleType(int inputVehicleType){
    VehicleType = inputVehicleType;
}


vehicle::~vehicle() {
    
}

int vehicle::get_ID(){return ID;}
void vehicle::set_ID(int inputID){ID = inputID;}
