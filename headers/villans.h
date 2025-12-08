#ifndef VILLANS_H
#define VILLANS_H
#include "actors.h"

class Bear : public Actor
{
private:
    vector<Bear *> family;
    bool isConcious;
public:
    void beHappyAboutReturnToHome();
    void eatsPorridge();
    void goesToSleep();
    void tryToCatch(Actor *target);
    void addToFamily(Actor *memberToAdd);
    void complainAboutPorridge(string heatLevel);
    Bear(string name,string location,Map* map);
};
class humanVillan : public Actor
{
    vector<Actor *> pupets;

public:
    void cryForFamily(vector <Bear*>bearsSurrogitiveFamilly);
    void takeGoonWithYou(string nameOfGoon);
};
#endif