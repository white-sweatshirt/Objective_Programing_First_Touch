#ifndef ANIMALS_H
#define ANIMALS_H
#include <iostream>
using namespace std;
class Person
{
protected:
    string name;
    int age;
    Animal *pet;

public:
    virtual void introduceYourself();
};
class Customer : public Person
{
private:
    double cashAtHand;

public:
    void askForHelpWithAnimal();
};
class Animal
{
protected:
    friend Customer;
    bool stomAche;
    string name;

public:
    virtual void giveVoice();
    virtual void healAnimal();
    virtual void beNamed();
};
class Dog
{
    bool illPawn;
public:
    void healAnimal();
    void giveVoice();
};
#endif