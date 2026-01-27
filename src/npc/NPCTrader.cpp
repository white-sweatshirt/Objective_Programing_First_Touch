#include "NPCTrader.h"
#include "Player.h"
void NPCTrader::giveOptionsInDialogue()
{
    // Implementation of dialogue options
}

void NPCTrader::sellItem(Player *player)
{
    
}

void NPCTrader::buyItem(Item *item)
{
    // Implementation of buying items
}

void NPCTrader::giveSelection()
{
    // Implementation of giving selection
}

double NPCTrader::giveFee()
{
    return penaltyRate; // Return the penalty rate (e.g., 10%)
}

void NPCShopKeeper::generateItems()
{
    items.push_back(new Weapon("Wizard Staff", 10));
    items.push_back(new Weapon("Wizard Wand", 8));
    items.push_back(new Weapon("Warrior Sword", 12));
    items.push_back(new Weapon("Warrior Shield", 10));
    items.push_back(new Weapon("Archer Bow", 9));
    items.push_back(new Weapon("Archer Crossbow", 11));
}

void NPCShopKeeper::giveSelection(void)
{
    templateLib::showContentsOfContainer(this->items);
}

void NPCShopKeeper::sellItem(Player *player)
{
    
}

void NPCShopKeeper::buyItem(Item *item)
{
    // TODO : implement
}
void NPCCrafter::destroyItem(Item *item)
{
    // TODO : implement
}
void NPCCrafter::createItem(Player* player, int damageBonus)
{
    if (!player)
        return;

    double cost = damageBonus * 3.0;
    if (player->getMoney() >= cost)
    {
        player->reduceMoney(cost);
        Items* newItem = new Weapon("Crafted Weapon", damageBonus);
        player->addItemToInventory(newItem);
    }
}
