#include "Player.h"
#include "Location.h"
#include "TemplateLib.h"
#include "Quest.h"
#include "NPCTrader.h"
#include "NPC.h"
#include "Weapon.h"

Player::Player(std::string customName)
    : ActiveActor(100, 100, 4, 4, 4), name(customName), level(1),
      experience(0), expToNextLevel(30), money(0)
{
}

void Player::goToNewPlace(Location *newPlace)
{
    this->placeOfBeing = newPlace;
}

void Player::interactWithNPC(NPC *npc)
{
    npc->giveOptionsInDialogue();
}

void Player::gainExperience(double amount)
{
    experience += amount;
}

void Player::askLocationToShowInterestingPlaces()
{
    if (placeOfBeing)
    {
        placeOfBeing->tellAboutInterestingLocations();
    }
    else
    {
        std::cout << "You are not in any location." << std::endl;
    }
}
void Player::equipItem(Items *item)
{

    if (item == nullptr)
        return;
    if (this->weapon != nullptr && this->weapon != item)
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
        expToNextLevel += 30; // Increment threshold for next level
        strenght += 4;
        agility += 4;
        inteligence += 4;
    }
}
void Player::sellItem(Items *item, NPCTrader *trader)
{
    if (!item || !trader)
        return;

    templateLib::removeElemetOfVector(this->items, item);

    double value = item->giveValue()* (1.0 - trader->giveFee());
    money += value;
}