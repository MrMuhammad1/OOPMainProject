#include <iostream>
#include <string>
#include "Vehicle.h"

#ifndef HELICOPTER_H
#define HELICOPTER_H

using namespace std;


class Helicopter:public vehicle{

protected:
int ID;
int PassengerSize;
double TimeInAir;

public:
int get_PassengerSize();
void set_PassengerSize(int in_PassengerSize);

double get_TimeInAir();
void set_TimeInAir(double i_TimeInAir);


};


#endif