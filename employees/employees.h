#ifndef PEOPLE_H
#define PEOPLE_H
// de facto people in my vetinary
#include "clients.h"
#include <iostream>
using namespace std;

class Vet : public Person
{

public:
    void introduceYourself();
    void healAnimal();     // as argument it will take name of animal
    void talkToCustomer(); // as argument it will take name of cusotmer
};
#endif