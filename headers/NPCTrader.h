#ifndef NPCTRADER_H
#define NPCTRADER_H

#include "NPC.h"


class NPCTrader : public NPC {
private:
    std::vector<std::string> itemListToSell;
    double penaltyRate = 0.1; // 10% penalty for buying items from the player

public:
    void giveOptionsInDialogue() override;
    void sellItem();
    void buyItem();
    void giveSelection();
    ~NPCTrader() override = default;
};
class NPCCrafter : public NPC {
public:
    void giveOptionsInDialogue() override;
    void craftItem(const std::string& itemName, double goldCost);
    ~NPCCrafter() override = default;
};
class NPCShopKeeper : public NPCTrader {
public:
    void giveOptionsInDialogue() override;
    void checkInventory();
    ~NPCShopKeeper() override = default;
};

#endif // NPCTRADER_H