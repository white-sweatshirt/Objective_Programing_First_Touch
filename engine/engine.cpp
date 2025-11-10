#include "engine.h"
Engine::Engine()
{
    this->engineOn=false;
}
void Engine::startEngine()
{
    if (!engineOn)
        this->engineOn = 1;
    else
        cout << "juz jest walczony \n";
}
void Engine::turnOffEngine()
{
    if (engineOn)
        this->engineOn = 0;
    else
        cout << "juz jest wylaczony \n";
}
EngineElectrical::EngineElectrical(int power, float energyLevel)
{
    this->power = power;
    this->energyLevel = energyLevel;
    this->engineOn = false;
}
EngineCombustion::EngineCombustion(int amountOfCylinders, int amountOfValve)
{
    this->amountOfCylinders = amountOfCylinders;
    this->amountOfValve = amountOfValve;
}