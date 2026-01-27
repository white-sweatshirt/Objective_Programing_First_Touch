#ifndef NPCTRADER_H
#define NPCTRADER_H

#include "NPC.h"
class Item;
class NPCTrader : public NPC
{
private:
    std::vector<std::string> itemListToSell;
    std::vector<Item *> itemList;
    double penaltyRate = 0.1; // 10% penalty for buying items from the player

public:
    virtual void giveOptionsInDialogue() override;
    virtual void sellItem();
    virtual void buyItem(Item *item);
    virtual void giveSelection();
    ~NPCTrader();
};
class NPCCrafter final: public NPC // final makes it imposiable for it to be virutral
{
public:
    void giveOptionsInDialogue() override;
    void craftItem(const std::string &itemName, double goldCost);
    void destroyItem(Item *item);
    ~NPCCrafter();
};
class NPCShopKeeper : public NPCTrader 
{
public:
    void giveOptionsInDialogue() override;
    void checkInventory();
    void giveSelection(void) override;
    void sellItem() final;// makes it impossiable to overwrite function in inheritance
    void buyItem(Item *item) override;
    ~NPCShopKeeper();
};

#endif // NPCTRADER_H