#ifndef ANIMALS_H
#define ANIMALS_H
#include "people.h"
using namespace std;

class Animal
{
    protected:
    friend Customer;
    public:
     virtual void giveVoice();
     
};
class Dog
{

};
#endif