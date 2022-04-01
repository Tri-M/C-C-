#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Car
{
double gaslevel;
double mpg;
public:
       Car(double mpg);
       void add_gas(double gas);
       void drive(double miles);
       double get_gas();
       };


       Car::Car(double mpg)
       {
       mpg = 0;

       gaslevel = 0.0;
       cout << "\nAverage of Car is " << mpg << "Miles/Gallon\n";
       }
       void Car::add_gas(double gas)
       {
       gaslevel=gaslevel+gas;
       }
       void drive(double miles)
       {
       cout<<"How many miles will you drive: ";
       cin >> miles;
       }
       double get_gas()
       {
       cout<<"You have "<<get_gas<<"Gallons Remaining\n";
       return 0;
       }
