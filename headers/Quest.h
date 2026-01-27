#ifndef QUEST_H
#define QUEST_H

#include <string>

class Quest
{
protected:
    bool complated;
    double reward;
public:
    virtual void sayWhatNeedsToBeDone() ;
    virtual bool checkFulfillmentCondition() ;
    double  giveReward();
    virtual ~Quest() = default;
};
class KillingQuest : public Quest
{
private:
    std::string enemyToKill;

public:
    void sayWhatNeedsToBeDone() override;
    
    ~KillingQuest() override = default;
};
class SearchQuest : public Quest
{
private:
    std::string itemToFind;

public:
    void sayWhatNeedsToBeDone() override;
    ~SearchQuest() override = default;
};
class HuntingQuest : public Quest
{
private:
    std::string creatureToKill;

public:
    void sayWhatNeedsToBeDone() override;
    
    ~HuntingQuest() override = default;
};
#endif // QUEST_H