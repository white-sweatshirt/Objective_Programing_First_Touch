#ifndef PROTAGONISTS_H
#define PROTAGONISTS_H

#include "actors.h"
#include "villans.h"
class Scene;
#include "scene.h"
class GhostOfPast;
class Protagonist : public Actor
{
    // nad anglia bitwa londyn sie smazy/ a ja w dozynki bawie sie na plazy/
private:
    bool isStressed;
    string possiableRoadToStar;

public:
    void makePlansForCapturingFlag(Protagonist *team[], int peopleInTeam);
    void doTherapy(Protagonist *target);
    void throwPodrigeOnVillan(Bear *villanBear, string heatLevel);
    void tryToStealMapFrom(Actor *mapHolder);
    void readMapByExtensionChangeScene(Scene *current);
    void talkWithGhost(GhostOfPast *ghost);

    Protagonist(string name, string startingLocation, Map *map);
    Protagonist();
    ~Protagonist();
};
class GhostOfPast
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