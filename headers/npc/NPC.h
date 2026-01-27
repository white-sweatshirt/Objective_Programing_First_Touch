#ifndef NPC_H
#define NPC_H

#include <vector>
#include <iostream>
class ActiveActor;
class Player;
class Quest;
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
    private:
    double healingFee;
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
    void giveQuest(Player *player);
    void giveRewardForQuest(Player *player,Quest *realisedQuest);
    void show() override;
    ~NPCQuestGiver() override = default;
};

#endif // NPC_H