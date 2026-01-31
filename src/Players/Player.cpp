#include "Player.h"
#include "Location.h"
#include "TemplateLib.h"
#include "Quest.h"
#include "NPCTrader.h"
#include "NPC.h"
#include "Item.h"

Player::Player(std::string customName)
    : ActiveActor(100, 100, 4, 4, 4), name(customName), level(1),
      experience(0), expToNextLevel(30), money(0)
{
}
void Player::showInventory(void)
{
    std::cout << "pokazywanie ekwypinku: " << std::endl;
    templateLib::showContentsOfContainerWithCounter(this->items);
}
void Player::showAllQuests(void)
{
    templateLib::showContentsOfContainer(this->questList);
}

bool Player::payForSth(double amount)
{
    if (amount > this->money)
    {
        std::cout << name << " nie stac na ta czynosc" << std::endl;
        return false;
    }
    else
    {
        if (amount > 0)
            this->money -= amount;
        else
            std::cout << "probowano zaplacic ujemna ilosc pieniedzy! " << std::endl;
    }
    return true;
}

void Player::gainExperience(double amount)
{
    experience += amount;
}

void Player::equipItem(Item *item)
{

    if (!item)
        return;
    if (this->weapon && this->weapon != item)
    {
        this->items.push_back(weapon);
        this->weapon = item;
        templateLib::removeElemetOfVector(this->items, item);
    }
}
void Player::getMonetaryReward(double reward)
{
    if (reward > 0)
        this->money += reward;
    else
        return;
}
void Player::addItemToInventory(Item *item)
{
    this->items.push_back(item);
}
void Player::reciveMoney(double amount)
{
    if (amount > 0)
        this->money += amount;
}
void Player::giveFulliedQuestsToNPC(NPCQuestGiver *npc)
{
    for (auto w : this->questList)
        npc->giveRewardForQuest(this, w);
}
void Player::receiveQuest(Quest *quest)
{
    if (quest)
        questList.push_back(quest);
}

void Player::gainExperienceFromEnemy(int exp)
{
    experience += exp;
    checkLevelUp();
}

void Player::checkLevelUp()
{
    if (experience >= expToNextLevel)
    {
        level++;
        experience -= expToNextLevel;
        expToNextLevel += 30;
        strenght += 4;
        agility += 4;
        inteligence += 4;
    }
}
void Player::sellItem(Item *item, NPCTrader *trader)
{
    if (!item || !trader)
        return;

    templateLib::removeElemetOfVector(this->items, item);

    double value = item->giveValue() * (1.0 - trader->giveFee());
    money += value;
}
Item *Player::choseSellingItem(void)
{
    int choice = -1;
    choice = templateLib::getStandardChoiceResult(this, showInventory, 0, items.size() - 1);
    Item *chosenItem = items[choice];
    templateLib::removeElemetOfVector(items, items[choice]);
    return chosenItem;
}
void Player::fullfillQuests(NPCQuestGiver *npc)
{
    for (auto  w : this->questList)
    {
        npc->giveRewardForQuest(this, w);
        if (w->checkFulfillmentCondition())
        {
            templateLib::removeElemetOfVector(this->questList, w);
            delete w;
        }
    }
}
Player::~Player()
{
    templateLib::killVectorOfPointers(this->items);
    templateLib::killVectorOfPointers(this->questList);
}