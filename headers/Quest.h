#ifndef QUEST_H
#define QUEST_H

#include <string>

class Quest {
public:
    virtual void sayWhatNeedsToBeDone() = 0;
    virtual void checkFulfillmentCondition() = 0;
    virtual ~Quest() = default;
};
class KillingQuest : public Quest {
private:
    std::string enemyToKill;

public:
    void sayWhatNeedsToBeDone() override;
    void checkFulfillmentCondition() override;
    ~KillingQuest() override = default;
};
class SearchQuest : public Quest {
private:
    std::string itemToFind;

public:
    void sayWhatNeedsToBeDone() override;
    void checkFulfillmentCondition() override;
    ~SearchQuest() override = default;
};
class HuntingQuest : public Quest {
private:
    std::string creatureToKill;

public:
    void sayWhatNeedsToBeDone() override;
    void checkFulfillmentCondition() override;
    ~HuntingQuest() override = default;
};
#endif // QUEST_H