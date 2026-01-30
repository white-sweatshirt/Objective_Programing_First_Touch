#include "NPCTrader.h"
#include "Player.h"
#include "Menu.h"

void NPCTrader::sellItem(Player *player, int numberChosen)
{
    if (player->payForSth(items[numberChosen]->giveValue()))
        player->addItemToInventory(items[numberChosen]);
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

void NPCTrader::showSellingOptions()
{
    int i = 0;
    i = templateLib::showContentsOfContainerWithCounter(items);
}
void NPCTrader::showOptions(void)
{
    std::cout << "0. kup bron" << std::endl;
    std::cout << "1. sprzedaj przedmiot" << std::endl;
    std::cout << "2. wyjdz z menu" << std::endl;
}
void NPCTrader::interprateChoice(int choice, Player *pc)
{

    int secundChoice = -1;
    Item *chosenItem = nullptr;
    switch (choice)
    {
    case 0:
        secundChoice = templateLib::getStandardChoiceResult(this,
                                                            showSellingOptions, 0, items.size() - 1);
        sellItem(pc, secundChoice);
        break;
    case 1:
        chosenItem = pc->choseSellingItem();
        pc->getMonetaryReward(this->buyItem(chosenItem));
        break;
    case 2:
        break;
    default:
        break;
    }
}

void NPCTrader::getUserToChoseOption(Player *pc)
{
    int i = 0, choice;
    std::cout << "Jestes w sklepie " << this->name;
    std::cout << "mozesz kupic takie itemki wpisujac odpowiednia opcje: " << std::endl;
    choice = templateLib::getStandardChoiceResult(this, showOptions, 0, items.size());
}
void NPCCrafter::showCraftingOptions(void)
{
    std::cout << "0. bez nazwy tylko parametry" << std::endl;
    std::cout << "1. z nazwa z parametrem" << std::endl;
    std::cout << "2. wyjdz z menu" << std::endl;
}
void NPCCrafter::showOptions(void)
{
    std::cout << "0. kup bron" << std::endl;
    std::cout << "1. sprzedaj przedmiot" << std::endl;
    std::cout << "2. stworz custom weapon" << std::endl;
    std::cout << "3. wyjdz z menu" << std::endl;
}
void NPCCrafter::giveMenuShowingMaxDemage(int maxDemage)
{
    std::cout << "min demage: " << 0 << std::endl;
    std::cout << "max demage: " << maxDemage << std::endl;
}
void NPCCrafter::interprateCraftingChoice(int choice, Player *pc)
{
    constexpr int maxDemage = 1000;
    int demageChosen = -1;
    std::string name;
    switch (choice)
    {
    case 0:

        demageChosen = templateLib::getStandardChoiceResult(this, giveMenuShowingMaxDemage, 0, maxDemage);
        createItem(pc, demageChosen);
    case 1:
        demageChosen = templateLib::getStandardChoiceResult(this, giveMenuShowingMaxDemage, 0, maxDemage);
        std::cout << "podaj nazwe swej broni: " << std::endl;
        std::cin>>name;
        createItem(pc, demageChosen,name);
        break;
    case 2:
        break;
    default:
        break;
    }
}
void NPCCrafter::interprateChoice(int choice, Player *pc)
{
    int secundChoice = -1;
    Item *chosenItem = nullptr;
    switch (choice)
    {
    case 0:
        // dynamic_cast allows to safly convert class member to one beging higher in hiearchy
        // cast required as showSellingOptions have no equlivalent in NPCCrafter
        secundChoice = templateLib::getStandardChoiceResult(dynamic_cast<NPCTrader *>(this),
                                                            showSellingOptions, 0, items.size() - 1);
        sellItem(pc, secundChoice);
        break;
    case 1:
        chosenItem = pc->choseSellingItem();
        pc->getMonetaryReward(this->buyItem(chosenItem));
        break;
    case 2:
        secundChoice = templateLib::getStandardChoiceResult(this, showCraftingOptions, 0, 2);
        interprateCraftingChoice(choice, pc);
    case 3:
        break;
    default:
        break;
    }
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
NPCCrafter::~NPCCrafter(void)
{
    
}