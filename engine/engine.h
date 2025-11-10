#ifndef ENGINE_H
#define ENGINE_H
#include <iostream>
using namespace std;

class Engine
{
protected:
    bool engineOn;

public:
    virtual void startEngine();
    virtual void turnOffEngine();
    Engine();
};

class EngineElectrical : virtual public Engine
{
protected:
    int power;
    float energyLevel;

public:
    EngineElectrical(int power, float energyLevel);
};

class EngineCombustion: virtual public Engine
{
protected:
    int amountOfCylinders;
    int amountOfValve; // zawor
public:
    EngineCombustion(int amountOfCylinders, int amountOfValve);
};

#endif