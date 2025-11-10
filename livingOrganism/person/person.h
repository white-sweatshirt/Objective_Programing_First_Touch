#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;
class Person
{
protected:
    string name;
    int age;
public:
    virtual void introduceYourself();
};
#endif