#ifndef PERSON_H
#define PERSON_H
#include "stdHeader.h"
class Person
{
protected:
    string name;
    int age;
public:
    virtual void introduceYourself();
};
#endif