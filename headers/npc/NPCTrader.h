#ifndef NPCTRADER_H
#define NPCTRADER_H

#include "NPC.h"
class Item;
class Player;
class Weapon;
class NPCTrader : public NPC
{
protected:
    std::vector<Item *> items;
    double penaltyRate = 0.1; // 10% penalty for buying items from the player
    virtual void showOptions(void) override;
    virtual void interprateChoice(int choice) override;
    virtual void interprateChoice(int choice , int itemsSold,Player *pc) ;

public:
    virtual void getUserToChoseOption(Player *pc) override;
    void sellItem(Player *player,int numberChosen);
    virtual double buyItem(Item *item);
    void generateItems();
    void show(void) override;
    double giveFee();
    ~NPCTrader();
};
class NPCCrafter final : public NPCTrader // final makes it imposiable for it to be virutral
{
private:
    void showOptions(void) override;

public:
    void getUserToChoseOption(Player *pc) override;
    void createItem(Player *player, int damageBonus);
    void createItem(Player *player, int damageBonus, std::string customName);
    void destroyItem(Item *item);
    void show(void) override;
    ~NPCCrafter();
};

#endif // NPCTRADER_H