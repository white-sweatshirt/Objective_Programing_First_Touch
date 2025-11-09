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
    double giveMoneyForTreatment(double costOfTreatment);
    void getLoan(double amount);
};

class Animal
{
protected:
    friend Customer;
    bool stomAche;
    string name;

public:
    virtual void giveName();
    virtual int beHealed();
};

class Dog : public Animal
{
    bool illPawn;
    bool tailHurts;
public:
    int beHealed();
    void giveVoice();
    void giveName();
};
#endif