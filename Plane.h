#include <iostream>
#include <string>
#include "Vehicle.h"

#ifndef PLANE_H
#define PLANE_H

using namespace std;

class Plane: public vehicle{

protected:
int ID;
string SizeType;
double Fuel;
int PassengerSize;
double TimeInAir;
string Origin;

public:
string get_SizeType();
void set_SizeType(string i_SizeType);
int get_Fuel();
void set_Fuel(double nFuel);
int get_PassengerSize();
void set_PassengerSize(int N_PassengerSize);
double get_TimeInAir();
void set_TimeInAir(int N_TimeInAir);
void FuelUsage(string SizeType, int Fuel, double TimeInAir);

};

#endif
