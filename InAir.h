#include "Vehicle.h"
#include <iostream>
#include <string>

#ifndef INAIR_H
#define INAIR_H

using namespace std;


class InAir  
{

protected:
int ID;
int NumOfPlane;
int AirLimit;
int numInAir;

public:
vehicle* VehiclesInAir = new vehicle[15];

int get_NumOfPlanes();
void set_NumOfPLanes(int i_NumOfPlanes);

void addVehicleInAir(vehicle inputVehicle);
void removeVehicleInAir(vehicle inputVehicle);
vehicle* get_usage();

int get_AirLimit();
void set_AirLimit(int i_AirLimit);

vehicle* get_VehiclesInAir();



};
#endif