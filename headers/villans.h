#ifndef VILLANS_H
#define VILLANS_H

#include "actors.h"
#include "mcguffin.h"

class Protagonist;
class GhostOfPast;

#include "protagonists.h"

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
    Bear(string name, string location);
    ~Bear();
};
class humanVillan : public Actor
{
    vector<Actor *> goons;
    Protagonist *prisonier;

public:
    humanVillan(string name, string locationOfBeing);
    humanVillan(string name, string location, Map *map);

    Protagonist *loseControlOverHero();
    void captureHero(Protagonist **toCapture);
    void askForHelpWithThief(vector<Bear *> &bearsSurrogitiveFamilly, Actor *thief);
    void takeGoonWithYou(string nameOfGoon);
    void sendGoonsToAttack(Actor *target);
    ~humanVillan();
};
class Death : public Actor
{
private:

public:
    void scareHero(Protagonist*target);
    void destroyGhost(GhostOfPast *target);
};
#endif