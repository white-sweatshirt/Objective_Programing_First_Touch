#include "actors.h"
Actor::Actor(string startingPlace, string nameOfActor) : nameOfActor(nameOfActor),
                                                         placeOfBeing(startingPlace)
{
    this->map = NULL;
}
Actor::Actor(string startingPlace,string nameOfActor,Map* map): nameOfActor(nameOfActor),
    placeOfBeing(startingPlace)
{
    this->map=map;
}
Actor::~Actor()
{
}

void Actor::attackActor(Actor *a)
{
    cout << this->giveName() << " attacking " << a->giveName();
}
void Actor::goToOtherActor(Actor *otherActor)
{
    cout << this->nameOfActor << " jestem kolo " << otherActor->giveName() << endl;
}
void Actor::goToNewPlace(string newPlace)
{
    cout << this->giveName() << " idzie z" << this->placeOfBeing << " do " << newPlace;
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
Map *Actor::loseMap()
{
    Map *map = this->map;
    this->map = NULL;
    return map;
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
 template<class friendClass> void Actor::transferMapOwnerShip(friendClass *ally)
{
    Map* map1=this->map;
    ally->getMap(map);
}
