#ifndef NPC_H
#define NPC_H

#include <vector>
#include <iostream>

class NPC {
public:
    virtual void giveOptionsInDialogue() = 0;
    virtual ~NPC() = default;
};

class NPCHealer : public NPC {
public:
    void giveOptionsInDialogue() override;
    void healForSmallFee();
    ~NPCHealer() override = default;
};
class NPCQuestGiver : public NPC {
public:
    void giveOptionsInDialogue() override;
    void giveQuest();
    void giveRewardForQuest();
    ~NPCQuestGiver() override = default;
};

#endif // NPC_H