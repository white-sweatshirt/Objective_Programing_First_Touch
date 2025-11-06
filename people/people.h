#ifndef PEOPLE_H
#define PEOPLE_H
// de facto people in my vetinary
#include <iostream>
using namespace std;
class Person
{
protected:
    string name;
    int age;
    class Pet *pet;
public:
    virtual void introduceYourself();
};
class Customer: public Person
{
    []
};
class Vet : public Person
{
    
    public:
    void introduceYourself();
    void healAnimal();// as argument it will take name of animal
    void talkToCustomer();// as argument it will take name of cusotmer
};
#endif