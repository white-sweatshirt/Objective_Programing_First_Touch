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
    double penaltyRate = 0.1;

    void showSellingOptions(void) ;
    virtual void interprateChoice(int choice ,Player *pc)override ;
    virtual void showOptions(void);
    void generateItems();
public:
    virtual void getUserToChoseOption(Player *pc) override;
    void sellItem(Player *player,int numberChosen);
    virtual double buyItem(Item *item);
    void show(void) override;
    double giveFee();
    NPCTrader();
    virtual ~NPCTrader();
};

// final makes it imposiable for class to be inherited
class NPCCrafter final : public NPCTrader 
{
private:
    void showOptions(void) override;
    
    void showCraftingNamesOptions() ;
    void interprateCraftingNamesChoice(int choice, Player *pc,Weapon * weapon);
    
    void showCraftingTypeOptions(void);
    void interprateCrafingTypeOptins(int choice,Player *pc);

    
    
    void giveMenuShowingMaxDemage(int maxDemage);
public:
    void interprateChoice(int choice ,Player *pc) override ;
    void getUserToChoseOption(Player *pc) override;
    void destroyItem(Item *item);
    void show(void) override;
    ~NPCCrafter();
};

#endif // NPCTRADER_H