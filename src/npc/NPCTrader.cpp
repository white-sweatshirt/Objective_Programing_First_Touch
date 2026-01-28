#include "NPCTrader.h"
#include "Player.h"
#include "structFunctions.h"
void NPCTrader::giveOptionsInDialogue()
{
    // Implementation of dialogue options
}

void NPCTrader::sellItem(Player *player)
{
}
NPCTrader::~NPCTrader()
{
    templateLib::killVectorOfPointers(this->items);
}

void NPCTrader::show()
{
    int lineCounter = 0;
    std::cout << "W ofercie mamy: ";
    for (auto const w : this->items)
    {
        std::cout << lineCounter << ". ";
        w->show();
    }
}

double NPCTrader::giveFee()
{
    return penaltyRate; // Return the penalty rate (e.g., 10%)
}

void NPCShopKeeper::generateItems()
{
    items.push_back(new MagicWeapon("Wizard Staff", 10));
    items.push_back(new MagicWeapon("Wizard Wand", 8));
    items.push_back(new MagicWeapon("Super Wand 2000", 400));
    items.push_back(new MeeleWeapon("Warrior Sword", 12));
    items.push_back(new MeeleWeapon("Warrior mega Sword", 300));
    items.push_back(new MeeleWeapon("Warrior Shield", 10));
    items.push_back(new RangedWeapon("Archer Bow", 9));
    items.push_back(new RangedWeapon("Archer Crossbow", 11));
    items.push_back(new RangedWeapon("Flame-Thrower", 300));
}

void NPCShopKeeper::giveSelection(void)
{
    
}

void NPCShopKeeper::sellItem(Player *player,Item* chosenItem)
{
    
}

double NPCShopKeeper::buyItem(Item *item)
{
    double valueOfItem = item->giveValue();
    this->items.push_back(item);
    return valueOfItem;
}
void NPCCrafter::show(void)
{
    int lineCounter = 0;
    std::cout << "W ofercie mamy: " << std::endl;
    templateLib::showContentsOfContainer(this->items);
    std::cout << "mamy ponadto mozliwosc craftignu custom equipmentu" << std::endl;
}
void NPCCrafter::destroyItem(Item *item)
{
    delete item;
    
}
void NPCCrafter::createItem(Player *player, int damageBonus)
{
    if (!player)
        return;
    double cost = damageBonus * 3.0;
    if (player->giveAccountStatus() >= cost)
    {
        player->payForSth(cost);
        Item *newItem = new Weapon("custom weapon 1", damageBonus);
        player->addItemToInventory(newItem);
    }
}

void NPCCrafter::createItem(Player *player, int damageBonus, std::string customName)
{
    if (!player)
        return;
    double cost = damageBonus * 3.0;
    if (player->giveAccountStatus() >= cost)
    {
        player->payForSth(cost);
        Item *newItem = new Weapon(customName, damageBonus);
        player->addItemToInventory(newItem);
    }
}
