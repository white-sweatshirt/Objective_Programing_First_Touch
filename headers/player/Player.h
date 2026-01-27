#include <vector>
#include <iostream>
#include <list>
#ifndef PLAYER_H
#define PLAYER_H
class NPC;
class Items;
class Weapon;
class Location;
class Quest;
class Player
{
protected:
    std::string name;
    int level;
    double expToNextLevel;
    double experience;
    std::vector<Quest> questList;
    Location *placeOfBeing;
    NPC *npc;
    std::list<Items *> items;
    Items *weapon;
    double money;

public:
    virtual void goToNewPlace(Location *newPlace);
    virtual void interactWithNPC(NPC *npc);
    virtual void gainExperience(double amount);
    void sellItem(Items *itemToSell);
    void askLocationToShowInterestingPlaces(); // New method
    void giveFulliedQuestsToNPC(NPCQuestGiver *npc);
     
    void equipItem(Items *itemToEquip);
    void getMonetaryReward(double reward);

    virtual ~Player() = default;
};

#include "Weapon.h"
#include "NPC.h"
#endif // PLAYER_H