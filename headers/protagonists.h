#ifndef PROTAGONISTS_H
#define PROTAGONISTS_H
#include "actors.h"
#include "villans.h"
class GhostOfPast;
class Protagonist : public Actor
{
private:
    bool isStressed;

public:
    void throwPodrigeOnVillan(Bear *villanBear, string heatLevel);
    void tryToStealMapFrom(Actor *mapHolder);
    void doTherapy(Protagonist *target);
    void talkWithGhost(GhostOfPast *ghost);
    Protagonist(string name, string startingLocation, Map *map);
    Protagonist();
    ~Protagonist();
};
class GhostOfPast : public Protagonist
{
private:
    string whatIDid;

public:
    void tellAboutItsellfToHero(Protagonist *target);
    void beDestoryedByDeath();
    GhostOfPast(string whatIDid);
    ~GhostOfPast();
};
#endif