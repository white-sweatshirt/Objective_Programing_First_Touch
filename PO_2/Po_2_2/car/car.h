#ifndef CAR_H
#define CAR_H
#include <iostream>
using namespace std;
class Mechanic;
class Car
{
private:
    friend Mechanic;
    int fuelLevel;
    bool technicalState;
    string name;

public:
    int giveFuelLevel();
    string giveName();
    bool giveTechnicalState();
    void changeName(string newName);
    Car(int fuelLevel, bool techincalState, string name);
};

class Person
{
    // class exitsts so There is less to Write
protected:
    string name;

public:
    void getName(string newName);
    void sayName();
    Person(string name);
};

class Mechanic : public Person
{
private:
    /* data */
public:
    void repair(Car *car);
    Mechanic(string name);
};

class Driver : public Person
{
public:
    bool canIDrive(Car *car);
    Driver(string name);
};
#endif