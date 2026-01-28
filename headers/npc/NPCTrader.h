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

public:
    virtual void giveOptionsInDialogue() override;
    virtual void sellItem(Player *player);
    virtual double buyItem(Item *item);
    virtual void giveSelection();
    void show(void)override;
    double giveFee();
    ~NPCTrader();
};
class NPCCrafter final : public NPCTrader // final makes it imposiable for it to be virutral
{
private:
public:
    void giveOptionsInDialogue() override;
    void createItem(Player *player, int damageBonus);
    void createItem(Player *player, int damageBonus, std::string customName);
    void destroyItem(Item *item);
    void show(void) override;
    ~NPCCrafter();
};
class NPCShopKeeper : public NPCTrader
{
private:
public:
    void giveOptionsInDialogue() override;
    void giveSelection(void) override;
    void sellItem(Player *player) final; // makes it impossiable to overwrite function in inheritance
    double buyItem(Item *item) override;
    void generateItems();
    void show(void) override;
    ~NPCShopKeeper();
};

#endif // NPCTRADER_H