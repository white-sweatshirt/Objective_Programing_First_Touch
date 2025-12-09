#include "actors.h"
Actor::Actor()
{
}

Actor::Actor(string name) : nameOfActor(name)
{
}

Actor::Actor(string nameOfActor, string startingPlace) : nameOfActor(nameOfActor),
                                                         placeOfBeing(startingPlace)
{
    this->map = NULL;
}

Actor::Actor(string nameOfActor, string startingPlace, Map *map) : nameOfActor(nameOfActor),
                                                                   placeOfBeing(startingPlace)
{
    this->map = map;
}
Actor::~Actor()
{
    for (auto w : alies)
        alies.pop_back();
}

void Actor::attackActor(Actor *a)
{
    cout << this->giveName() << " attacking " << a->giveName() << endl;
}
string Actor::givePosition()
{
    return this->placeOfBeing;
}
void Actor::goToOtherActor(Actor *otherActor)
{
    cout << this->nameOfActor << " jestem kolo " << otherActor->giveName() << endl;
    this->placeOfBeing = "blisko " + otherActor->placeOfBeing;
}
void Actor::goToNewPlace(string newPlace)
{
    cout << this->giveName() << " idzie od " << this->placeOfBeing << " do " << newPlace;
    cout << endl;
    this->placeOfBeing = newPlace;
}
string Actor::giveName()
{
    return this->nameOfActor;
}
bool Actor::sayWheterYouHaveMap()
{
    if (this->map)
        return true;
    else
        return false;
}
bool Actor::checkWheterIsFriend(Actor *actorTocheck)
{
    for (auto w : this->alies)
        if (w == actorTocheck)
            return true;
    return false;
}

void Actor::getMap(Map *map)
{
    if (map)
        this->map = map;
    else
        cerr << "no map to pick up" << endl;
}

Map *Actor::loseMap()
{
    Map *map = this->map;
    this->map = NULL;
    return map;
}

Map *Actor::throwMap()
{
    Map *mapis = this->map;
    this->map = NULL;
    return mapis;
}

void Actor::tryToStealMapFrom(Actor *mapHolder)
{
    if (checkWheterIsFriend(mapHolder))
    {
        cout << "podaj mape " << mapHolder->giveName();
    }
    else
        cout << this->nameOfActor << "probuje ukrasc mape od: " << mapHolder->giveName();

    if (mapHolder->sayWheterYouHaveMap())
    {
        this->map = mapHolder->loseMap();
        cout << this->nameOfActor << "zdobyl mape";
    }
}
void Actor::transferMapOwnerShip(Actor *ally)
{
    Map *map1 = this->map;
    this->map = NULL;
    ally->getMap(map);
}
