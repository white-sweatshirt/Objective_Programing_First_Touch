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
class SubLocation;
#include "ActiveActor.h"
#include <deque>
class Player : public virtual ActiveActor
{
protected:
    std::string name;
    int level;
    
    double expToNextLevel;
    double experience;

    std::vector<Quest *> questList;
    
    std::deque<Item *> items;
    Item *weapon;
    double money;
    void showSellingOptions(void);
public:
    Player(std::string customName); // Added constructor declaration
    // it will be in loop that will be telling whats
    // user wants to do next;
    void receiveQuest(Quest *quest);
    void reciveMoney(double amount);

    void fullfillQuests(NPCQuestGiver *npc);
    void gainExperienceFromEnemy(int exp);

    virtual void interactWithNPC(NPC *npc);
    virtual void gainExperience(double amount);

    void giveFulliedQuestsToNPC(NPCQuestGiver *npc);
    void equipItem(Item *itemToEquip);
    void getMonetaryReward(double reward);
    void sellItem(Item *item, NPCTrader *trader);
    Item* choseSellingItem(void);
    void showAllQuests(void);
    void addItemToInventory(Item *item);
    void showInventory(void);
    bool payForSth(double amount);
    void checkLevelUp();

    virtual ~Player();
};

#include "Item.h"
#include "NPC.h"
#endif // PLAYER_H