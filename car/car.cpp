#include "car.h"
Car::Car(int fuelLevel, bool techincalState)
{
    this->fuelLevel = fuelLevel;
    this->technicalState = techincalState;
}
int Car::giveFuelLevel()
{
    return this->fuelLevel;
}
bool Car::giveTechnicalState()
{
    return this->technicalState;
}
void Car::changeName(string newName)
{
    this->name = newName;
}
void Person::getName(string newName)
{
    this->name = newName;
}
Person::Person(string name)
{
    this->name=name;
}
Driver::Driver(string name): Person(name)
{
    
}
bool Driver::canIDrive(Car *const car)
{
    if (car->giveFuelLevel() < 10 || !car->giveTechnicalState())
        return false;
    else
        return true;
}
Mechanic::Mechanic(string name) : Person(name)
{
    
}
void Mechanic::repair(Car *car)
{
    // using diractly attribiutes witohut helping class
    car->fuelLevel = 60;
    car->technicalState = 1;
  
}
