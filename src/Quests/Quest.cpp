#include "Quest.h"

void Quest::sayWhatNeedsToBeDone()
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
bool Quest::isFulfilled()
{
    return this->complited;
}


