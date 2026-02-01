#ifndef QUEST_H
#define QUEST_H

#include <string>

class Location; // Forward declaration of Location class

class Quest
{
protected:
    bool complited;
    double reward;
    Location *location; // Pointer to the location
public:
    virtual void show();
    virtual bool checkFulfillmentCondition();
    double giveReward();
    virtual void getOnePointOfProgress() = 0;
    void setLocation(Location *loc); // Modified to accept a Location pointer
    virtual ~Quest();
};
class KillingQuest : public Quest
{
private:
    int creaturesKilled;
    int craeturesToKill;

public:
    void show() override;
    void getOnePointOfProgress();
    ;
    KillingQuest(int creaturesToKill);
    KillingQuest();
    virtual ~KillingQuest() = default;
};
class SearchQuest : public Quest
{
private:
    int itemsFounded;
    int itemsMeantToBeFound;

public:
    void show() override;
    void addItemFinded();
    void getOnePointOfProgress();
    SearchQuest(int itemsToFind);
    ~SearchQuest() override = default;
};
#endif // QUEST_H
#include "ActiveActor.h"