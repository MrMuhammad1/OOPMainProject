#include "Plane.h"

using namespace std;


string Plane::get_SizeType()
{
    return SizeType;
}

void Plane::set_SizeType(string i_SizeType)
{
    SizeType = i_SizeType; // Assign the parameter value to the member variable
}

int Plane::get_Fuel()
{
    return Fuel;
}

void Plane::set_Fuel(double nFuel)
{
    Fuel = nFuel; // Assign the parameter value to the member variable
}

int Plane::get_PassengerSize()
{
    return PassengerSize;
}

void Plane::set_PassengerSize(int N_PassengerSize)
{
    PassengerSize = N_PassengerSize; // Assign the parameter value to the member variable
}

double Plane::get_TimeInAir()
{
    return TimeInAir;
}

void Plane::set_TimeInAir(int N_TimeInAir)
{
    TimeInAir = N_TimeInAir; // Assign the parameter value to the member variable
}

void Plane::FuelUsage(string SizeType, int Fuel, double TimeInAir)
{
    // Implement your FuelUsage logic here
}
