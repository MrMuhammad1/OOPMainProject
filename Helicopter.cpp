#include <iostream>
using namespace std;

#include "Helicopter.h"

int Helicopter::get_PassengerSize()
{
    return PassengerSize;
}

void Helicopter::set_PassengerSize(int in_PassengerSize)
{
    PassengerSize = in_PassengerSize; // Assign the parameter value to the member variable
}

double Helicopter::get_TimeInAir()
{
    return TimeInAir;
}

void Helicopter::set_TimeInAir(double i_TimeInAir)
{
    TimeInAir = i_TimeInAir; // Assign the parameter value to the member variable
}

