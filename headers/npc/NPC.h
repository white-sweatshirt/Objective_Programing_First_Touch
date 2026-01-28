#ifndef NPC_H
#define NPC_H

#include <vector>
#include <iostream>
class ActiveActor;
class Player;
class Quest;
class NPC
{
    //virtural class
private:
    std::string name;
protected:
virtual void showOptions(void);
public:
    virtual void giveOptionsInDialogue();
    virtual void show();
    virtual ~NPC() = default;
};

class NPCHealer : public NPC
{
    private:
    double healingFee;
     void showOptions(void)override;
public:
    void giveOptionsInDialogue() override;
    void healPlayerForFee(ActiveActor *pCharacter);
    void show() override;
    ~NPCHealer() override = default;
};
#include <list>
class NPCQuestGiver : public NPC
{
    private:
     void showOptions(void)override;
public:
    void giveOptionsInDialogue() override;
    void giveQuest(Player *player);
    void giveRewardForQuest(Player *player,Quest *realisedQuest);
    void show() override;
    ~NPCQuestGiver() override = default;
};

#endif // NPC_H