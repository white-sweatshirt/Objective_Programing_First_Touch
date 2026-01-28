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
    void setLocation(Location *loc); // Modified to accept a Location pointer
    virtual ~Quest() = default;
};
class KillingQuest : public Quest
{
private:
    int creaturesKilled;
    int craeturesToKill;
public:
    void show() override;
    void addKilling();
    KillingQuest();
    ~KillingQuest();
};
class SearchQuest : public Quest
{
private:
    int itemsFounded;
    int itemsMeantToBeFound;
public:
    void show() override;
    void addItemFinded();
    ~SearchQuest() override = default;
};
class HuntingQuest : public Quest
{
private:
    std::string creatureToKill;

public:
    void show() override;
    
    ~HuntingQuest() override = default;
};
#endif // QUEST_H
#include "ActiveActor.h"