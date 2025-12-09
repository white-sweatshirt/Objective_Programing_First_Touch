#ifndef VILLANS_H
#define VILLANS_H

#include "actors.h"
#include "mcguffin.h"

class Bear : public Actor
{
private:
    bool isConcious;
    bool eatenPorridge;

public:
    void beHappyAboutReturnToHome();
    void eatPorridge();
    void goesToSleep();
    void wakeUp();
    void tryToCatch(Actor *target);
    void complainAboutPorridge(string heatLevel);
    Bear(string name, string location, Map *map);
    Bear(string name,string location);
    ~Bear();
};
class humanVillan : public Actor
{
    vector<Actor *> goons;
    Actor * prisonier;

public:
    humanVillan(string name,string locationOfBeing);
    humanVillan(string name,string location,Map * map);

    void captureHero(Actor *toCapture);
    void askForHelpWithThief(vector<Bear *>& bearsSurrogitiveFamilly,Actor *thief);
    void takeGoonWithYou(string nameOfGoon);
    
    ~humanVillan();
};
#endif