#include <vector>
#include <iostream>
#include <list>
#ifndef PLAYER_H
#define PLAYER_H
class NPC;
class Items;
class Weapon;
class Location;

class Player
{
protected:
    std::string name;
    int level;
    double experience;
    std::vector<std::string> questList;
    Location* placeOfBeing;
    NPC* npc;
    std::list<Items*> items;
    Items* weapon;

public:
    virtual void goToNewPlace(Location * newPlace);
    virtual void interactWithNPC(NPC* npc);
    virtual void gainExperience(double amount);
    void sellItem(Items *itemToSell);
    void askLocationToShowInterestingPlaces(); // New method
    void equipItem(Items *itemToEquip);
    virtual ~Player() = default;
};

#include "Weapon.h"
#include "NPC.h"
#endif // PLAYER_H