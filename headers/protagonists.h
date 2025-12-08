#ifndef PROTAGONISTS_H
#define PROTAGONISTS_H
#include "actors.h"
#include "villans.h"
class GhostOfPast;
class Protagonist : public Actor
{
private:
    /* data */
public:
    void throwPodrigeOnVillan(Bear *villanBear, string heatLevel);
    void tryToStealMapFrom(Actor *mapHolder);
    void doTherapy(Protagonist *target);
    void talkWithGhost(GhostOfPast * ghost);
    Protagonist(string name, string startingLocation, Map *map);
    ~Protagonist();
};
class GhostOfPast : public Protagonist
{
private:
    string whatItDid;

public:
    void tellAboutItsellfToHero(Protagonist *target);
    void beDestoryedByDeath();
    ~GhostOfPast();
};
#endif