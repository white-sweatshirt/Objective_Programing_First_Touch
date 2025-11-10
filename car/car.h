#ifndef CAR_H
#define CAR_H
#include <iostream>
using namespace std;
class Car
{
private:
    friend Mechanic;
    int fuelLevel;
    bool technicalState;
    string name;

public:
    int giveFuelLevel();
    bool giveTechnicalState();
    void changeName(string newName);
    Car(int fuelLevel, bool techincalState);
};

class Person
{
    protected :
    string name;
    public:
    void getName(string newName);
    Person(string name);
};

class Mechanic: public Person
{
private:
    /* data */
public:
    void repair(Car *car);
      Mechanic(string name);
};

class Driver: public Person
{
public:
    bool canIDrive(Car *car);
    Driver(string name);
};
#endif