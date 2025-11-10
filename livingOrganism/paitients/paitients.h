#ifndef PAITIENTS_H
#define PAITIENTS_H
#include "stdHeader.h"
class Animal
{
protected:
    bool stomAche;
    string name;

public:
    virtual void giveName();
    virtual int beHealed();
};
class Dog : public Animal
{
    bool hasCold;
    bool illPawn;
    bool tailHurts;
public:
    int beHealed();
    void giveVoice();
    void giveName();
    Dog(string name);
};
class Parot : public Animal
{
    bool brokenWing;
    bool feathersWithoutColor;
public:
    int beHealed();
    void giveVoice();
    void giveName();
};
#endif