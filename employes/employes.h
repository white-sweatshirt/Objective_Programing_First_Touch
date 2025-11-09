#ifndef PEOPLE_H
#define PEOPLE_H
// de facto people in my vetinary
#include <iostream>
#include "clients.h"
using namespace std;


class Vet : public Person
{ 
    // degree i.e master , doctor
    string degree;
public:
    void introduceYourself();
    double serveCustomer(Animal * paitinet);// as group function for healing and for giving recipe
    void talkToCustomer(); // as argument it will take name of cusotmer
};
#endif