#ifndef NPC_H
#define NPC_H

#include <vector>
#include <iostream>
class ActiveActor;
class NPC
{
public:
    virtual void giveOptionsInDialogue();
    
    virtual ~NPC() = default;
};

class NPCHealer : public NPC
{
public:
    void giveOptionsInDialogue() override;
    void healPlayerForFee(ActiveActor *pCharacter);

    ~NPCHealer() override = default;
};
class NPCQuestGiver : public NPC
{
public:
    void giveOptionsInDialogue() override;
    void giveQuest();
    void giveRewardForQuest();
    ~NPCQuestGiver() override = default;
};

#endif // NPC_H