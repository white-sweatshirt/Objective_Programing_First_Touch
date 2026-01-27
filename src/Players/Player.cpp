#include "Player.h"
#include "Location.h"
#include "TemplateLib.h"
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
        this-> money+= reward;
    else
        return;
}
void Player::giveFulliedQuestsToNPC(NPCQuestGiver *npc)
{
    for(auto w:this->questList)
        npc->giveRewardForQuest(this,w);
}