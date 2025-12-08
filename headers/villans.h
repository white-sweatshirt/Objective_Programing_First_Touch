#ifndef VILLANS_H
#define VILLANS_H
#include "actors.h"

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
    ~Bear();
};
class humanVillan : public Actor
{
    vector<Actor *> goons;

public:
    void cryForFamily(vector<Bear *> bearsSurrogitiveFamilly);
    void takeGoonWithYou(string nameOfGoon);
    ~humanVillan();
};
#endif