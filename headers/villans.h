#ifndef VILLANS_H
#define VILLANS_H

#include "actors.h"
#include "mcguffin.h"

typedef enum a{FALSE,TRUE} boolean;

class Bear : public Actor
{
private:
    vector<Actor *> family;
    bool isConcious;
    bool eatenPorridge;

public:
    void beHappyAboutReturnToHome();
    void eatPorridge();
    void goesToSleep();
    void tryToCatch(Actor *target);
    void addToFamily(Actor *memberToAdd);
    void complainAboutPorridge(string heatLevel);
    Bear(string name, string location, Map *map);
    Bear(string name,string location);
    ~Bear();
};
class humanVillan : public Actor
{
    vector<Actor *> goons;

public:
    humanVillan(string name,string locationOfBeing);
    humanVillan(string name,string location,Map * map);
    void cryToFamily(vector<Actor *> bearsSurrogitiveFamilly);
    void takeGoonWithYou(string nameOfGoon);
    ~humanVillan();
};
#endif