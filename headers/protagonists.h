#ifndef PROTAGONISTS_H
#define PROTAGONISTS_H
#include "actors.h"
#include "villans.h"
class Protagonist : public Actor
{
private:
    /* data */
public:
    void throwPodrigeOnVillan(Bear *unLuckyOne, string heatLevel);
    void tryToStealMapFrom(Actor *mapHolder);
    void doTherapy(Protagonist *target);
    Protagonist(string name, string startingLocation,Map*map);
    ~Protagonist();
};
#endif