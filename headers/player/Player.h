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
#include "ActiveActor.h"
class Player : public virtual ActiveActor
{
protected:
    std::string name;
    int level;
    double expToNextLevel;
    double experience;
    std::vector<Quest *> questList; // Corrected type
    Location *placeOfBeing;
    std::list<Item *> items;
    Item *weapon;
    double money;

    void checkLevelUp(); // Added protected method

public:
    Player( std::string customName); // Added constructor declaration
   
    void receiveQuest(Quest *quest);
    void reciveMoney(double amount);
    void fullfillQuests(NPCQuestGiver * npc);
    void gainExperienceFromEnemy(int exp);

    virtual void goToNewPlace(Location *newPlace);
    virtual void interactWithNPC(NPC *npc);
    virtual void gainExperience(double amount);
    
    void askLocationToShowInterestingPlaces();
    void giveFulliedQuestsToNPC(NPCQuestGiver *npc);
    void equipItem(Item *itemToEquip);
    void getMonetaryReward(double reward);
    void sellItem(Item *item, NPCTrader *trader);
    void addItemToInventory(Item *item);
    double giveAccountStatus(void);
    void payForSth(double amount);
     ~Player();
};

#include "Item.h"
#include "NPC.h"
#endif // PLAYER_H