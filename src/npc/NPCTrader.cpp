#include "NPCTrader.h"
#include "Player.h"
#include "Menu.h"
void NPCTrader::getUserToChoseOption(Player *player)
{
}

void NPCTrader::sellItem(Player *player, int numberChosen)
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
void NPCTrader::sellItem(Player *player, int numberChosen)
{
    items[numberChosen]->giveValue();
}

double NPCTrader::buyItem(Item *item)
{
    double valueOfItem = item->giveValue();
    this->items.push_back(item);
    return valueOfItem;
}
void NPCTrader::generateItems()
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
void NPCTrader::interprateChoice(int choice, int itemsSold, Player *pc)
{
    if (choice < itemsSold)

        sellItem(pc, choice);

    else
    {
        // player shows all items so that they can be sold
        // then shop adds item to its display.
    }
}
void NPCTrader::showOptions()
{
    int i = 0;
    i = templateLib::showContentsOfContainerWithCounter(items);
    std::cout << ++i << ". sprzedaj itemek";
}
void NPCTrader::getUserToChoseOption(Player *pc)
{
    int i = 0, choice;
    std::cout << "Jestes w sklepie " << this->name;
    std::cout << "mozesz kupic takie itemki wpisujac odpowiednia opcje: " << std::endl;
    choice = templateLib::getStandardChoiceResult(this, showOptions, 0, items.size());
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
    if (player->payForSth(cost))
    {
        Item *newItem = new Weapon("custom weapon 1", damageBonus);
        player->addItemToInventory(newItem);
    }
}

void NPCCrafter::createItem(Player *player, int damageBonus, std::string customName)
{
    if (!player)
        return;
    double cost = damageBonus * 3.0;
    if (player->payForSth(cost))
    {
        Item *newItem = new Weapon(customName, damageBonus);
        player->addItemToInventory(newItem);
    }
}
