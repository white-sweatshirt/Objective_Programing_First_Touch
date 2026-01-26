#ifndef NPCTRADER_H
#define NPCTRADER_H

#include "NPC.h"

class NPCTrader : public NPC
{
private:
    std::vector<std::string> itemListToSell;
    double penaltyRate = 0.1; // 10% penalty for buying items from the player

public:
    virtual void giveOptionsInDialogue() override;
    virtual void sellItem();
    virtual void buyItem();
    virtual void giveSelection();
    ~NPCTrader();
};
class NPCCrafter : public NPC
{
public:
    void giveOptionsInDialogue() override;
    void craftItem(const std::string &itemName, double goldCost);
    ~NPCCrafter();
};
class NPCShopKeeper : public NPCTrader
{
public:
    void giveOptionsInDialogue() override;
    void checkInventory();
    void giveSelection(void) override;
    ~NPCShopKeeper();
};

#endif // NPCTRADER_H