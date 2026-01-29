#include <vector>
#include <iostream>
#include <list>
#ifndef PLAYER_H
#define PLAYER_H
class NPC;
class NPCTrader;
class NPCQuestGiver;
class Item;
class Weapon;
class Location;
class Quest;
class ImportantPlace;
#include "ActiveActor.h"

class Player : public virtual ActiveActor
{
protected:
    std::string name;
    int level;
    
    Location *placeOfBeing;
    ImportantPlace *sublocation;
    
    double expToNextLevel;
    double experience;

    std::vector<Quest *> questList;
    
    std::list<Item *> items;
    Item *weapon;
    double money;



    void checkLevelUp();

public:
    Player(std::string customName); // Added constructor declaration
    // it will be in loop that will be telling whats
    // user wants to do next;
    void receiveQuest(Quest *quest);
    void reciveMoney(double amount);

    void fullfillQuests(NPCQuestGiver *npc);
    void gainExperienceFromEnemy(int exp);

    virtual void goToNewPlace(Location *newPlace);
    virtual void interactWithNPC(NPC *npc);
    virtual void gainExperience(double amount);

    void askLocationToShowInterestingPlaces();
    void giveFulliedQuestsToNPC(NPCQuestGiver *npc);
    void equipItem(Item *itemToEquip);
    void getMonetaryReward(double reward);
    void sellItem(Item *item, NPCTrader *trader);

    void giveSellsOptions();
    void addItemToInventory(Item *item);
    bool payForSth(double amount);
    virtual ~Player();
};

#include "Item.h"
#include "NPC.h"
#endif // PLAYER_H