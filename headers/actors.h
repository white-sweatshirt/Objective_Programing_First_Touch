#ifndef ACTORS_H
#define ACTORS_H

#include <iostream>
#include <vector>
using namespace std;
#include "mcguffin.h"
class Actor
{
protected:
    /* data */
    string const nameOfActor;
    string placeOfBeing;
    Map * map;
    vector <Actor*> alies;
public:
    /*methods*/
    virtual void goToOtherActor(Actor *other);
    virtual bool sayWheterYouHaveMap();
    virtual void getMap(Map * map);
    virtual void goToNewPlace(string newPlace);
    virtual string giveName();
    virtual void attackActor(Actor *a);
    virtual void tryToStealMapFrom(Actor *mapHolder);
    virtual bool checkWheterIsFriend(Actor *actorTocheck);
    template<class friendClass> void transferMapOwnerShip(friendClass *ally);
    virtual Map* loseMap();
    virtual Map*throwMap();
    
    Actor(string startingPlace, string nameOfActor);
    Actor(string startingPlace,string nameOfActor,Map *map);
    ~Actor();
};

#endif