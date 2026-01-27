#ifndef NPCTRADER_H
#define NPCTRADER_H

#include "NPC.h"
class Item;
class Player;
class Weapon;
class NPCTrader : public NPC
{
protected:
    std::vector<std::string> itemListToSell;
    std::vector<Weapon *> items;
    double penaltyRate = 0.1; // 10% penalty for buying items from the player

public:
    virtual void giveOptionsInDialogue() override;
    virtual void sellItem(Player *player);
    virtual void buyItem(Item *item);
    virtual void giveSelection();
    double giveFee();
    ~NPCTrader();
};
class NPCCrafter final : public NPC // final makes it imposiable for it to be virutral
{
public:
    void giveOptionsInDialogue() override;
    void createItem(Player *player, int damageBonus);
    void destroyItem(Item *item);
    ~NPCCrafter();
};
class NPCShopKeeper : public NPCTrader
{
public:
    void giveOptionsInDialogue() override;
    void checkInventory();
    void giveSelection(void) override;
    void sellItem(Player *player) final; // makes it impossiable to overwrite function in inheritance
    void buyItem(Item *item) override;
    void generateItems();
    ~NPCShopKeeper();
};

#endif // NPCTRADER_H