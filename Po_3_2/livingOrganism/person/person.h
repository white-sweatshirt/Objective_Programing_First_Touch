#ifndef PERSON_H
#define PERSON_H
#include "stdHeader.h"
class Person
{
protected:
    double moneyAtHand;
    string name;
    int age;

public:
    virtual void introduceYourself();
};
#endif