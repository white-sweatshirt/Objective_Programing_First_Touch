#include "Quest.h"

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
void SearchQuest::show()
{

    std::cout << "musisz znalezc tyle przedmiotow" << this->itemsMeantToBeFound << std::endl;
    std::cout << "obcenie znalazles: " << this->itemsFounded << std::endl;
}
void KillingQuest::show()
{
    std::cout << "musisz zabic tylu przeciwnikow" << this->craeturesToKill << std::endl;
    std::cout << "obcenie zabiles: " << this->creaturesKilled << std::endl;
}
KillingQuest::KillingQuest()
{
    this->craeturesToKill = 4;
    this->creaturesKilled = 0;
}
void KillingQuest::addKilling()
{
    if (creaturesKilled < craeturesToKill)
    {
        creaturesKilled++;
        show();
    }
    else
        complited = 1;
}
