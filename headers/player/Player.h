#include <vector>
#include <iostream>
#include <list>
#ifndef PLAYER_H
#define PLAYER_H
class NPC;
class NPCTrader;
class NPCQuestGiver;
class Items;
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
    NPC *npc;
    std::list<Items *> items;
    Items *weapon;
    double money;

    void checkLevelUp(); // Added protected method

public:
    Player( std::string customName); // Added constructor declaration
   
    void receiveQuest(Quest *quest);
    void receiveMoneyForQuest(Quest *quest, NPCQuestGiver *npc);
    void gainExperienceFromEnemy(int exp);

    virtual void goToNewPlace(Location *newPlace);
    virtual void interactWithNPC(NPC *npc);
    virtual void gainExperience(double amount);
    
    void askLocationToShowInterestingPlaces();
    void giveFulliedQuestsToNPC(NPCQuestGiver *npc);
    void equipItem(Items *itemToEquip);
    void getMonetaryReward(double reward);
    void sellItem(Items *item, NPCTrader *trader);
    void addItemToInventory(Items *item);
    double getMoney();
    void reduceMoney(double cost);
    virtual ~Player() = default;
};

#include "Weapon.h"
#include "NPC.h"
#endif // PLAYER_H