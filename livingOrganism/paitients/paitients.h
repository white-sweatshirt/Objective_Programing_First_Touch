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
    virtual void sayName();
    virtual int beHealed();
    virtual void giveVoice();
    virtual string giveName();
};
class Dog : public Animal
{
    bool hasCold;
    bool illPawn;
    bool tailHurts;

public:
    int beHealed();
    void giveVoice();
    void sayName();
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
    void sayName();
};
#endif