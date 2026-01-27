#ifndef NPC_H
#define NPC_H

#include <vector>
#include <iostream>
class ActiveActor;
class NPC
{
private:
    std::string name;

public:
    virtual void giveOptionsInDialogue();
    virtual void show();
    virtual ~NPC() = default;
};

class NPCHealer : public NPC
{
public:
    void giveOptionsInDialogue() override;
    void healPlayerForFee(ActiveActor *pCharacter);
    void show() override;
    ~NPCHealer() override = default;
};
class NPCQuestGiver : public NPC
{
public:
    void giveOptionsInDialogue() override;
    void giveQuest();
    void giveRewardForQuest();
    void show() override;
    ~NPCQuestGiver() override = default;
};

#endif // NPC_H