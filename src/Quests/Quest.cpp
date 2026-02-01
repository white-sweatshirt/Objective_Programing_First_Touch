#include "Quest.h"
#include <iostream>
Quest::~Quest(void)
{
    this->location = nullptr;
}
void Quest::show()
{
}
bool Quest::checkFulfillmentCondition()
{
    return this->complited;
}
double Quest::giveReward()
{
    return this->complited ? reward : 0.0; // Return reward only if the quest is completed
}

void Quest::setLocation(Location *loc)
{
    this->location = loc; // Assign the location to the quest
}
void SearchQuest::addItemFinded()
{
    if (itemsFounded < itemsMeantToBeFound)
    {
        itemsFounded++;
        show();
    }
    else
        complited = true;
}
SearchQuest::SearchQuest(int itemToFind) : itemsMeantToBeFound(itemToFind)
{
    this->itemsFounded = 0;
}
void SearchQuest::show()
{

    std::cout << "musisz znalezc tyle przedmiotow" << this->itemsMeantToBeFound << std::endl;
    std::cout << "obcenie znalazles: " << this->itemsFounded << std::endl;
}
void SearchQuest::getOnePointOfProgress(void)
{
    this->itemsFounded++;
    if (checkFulfillmentCondition())
        complited = true;
}
void KillingQuest::getOnePointOfProgress(void)
{
    creaturesKilled++;
    if (checkFulfillmentCondition())
        complited = true;
}
void KillingQuest::show()
{
    std::cout << "musisz zabic tylu przeciwnikow" << this->craeturesToKill << std::endl;
    std::cout << "obcenie zabiles: " << this->creaturesKilled << std::endl;
}
KillingQuest::KillingQuest(int creaturesToKill) : craeturesToKill(creaturesToKill)
{
    this->creaturesKilled = 0;
}
KillingQuest::KillingQuest()
{
    this->craeturesToKill = 4;
    this->creaturesKilled = 0;
}
