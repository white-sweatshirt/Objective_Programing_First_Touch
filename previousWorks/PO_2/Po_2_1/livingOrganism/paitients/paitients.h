#ifndef PAITIENTS_H
#define PAITIENTS_H
#include "stdHeader.h"
class Animal
{
    // animal is virutral class needed so we have simpler customer class
protected:
    bool stomAche;
    string name;

public:
    virtual void giveName();
    virtual int beHealed();
    virtual void giveVoice();
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
class Parrot : public Animal
{
    bool brokenWing;
    bool feathersWithoutColor;

public:
    Parrot(string name);
    int beHealed();
    void giveVoice();
    void giveName();
};
#endif