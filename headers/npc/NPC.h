#ifndef NPC_H
#define NPC_H

#include <vector>
#include <iostream>
class ActiveActor;
class Player;
class Quest;
class NPC
{
    // virtural class:

protected:
    virtual void showOptions(void);
    virtual void interprateChoice(int choice, Player *pc)=0;

    std::string name;

public:
    
    virtual void askForUserInput(void);
    virtual void getUserToChoseOption(Player *pc);
    virtual void show();
    virtual ~NPC() = default;
};

class NPCHealer : public NPC
{
private:
    double healingFee;
    void showOptions(void) ;
    virtual void interprateChoice(int choice, Player *pc) override;

public:
    virtual void getUserToChoseOption(Player *pc);
    void healPlayerForFee(ActiveActor *pCharacter);
    void show() override;
    ~NPCHealer() override = default;
};
#include <list>
class NPCQuestGiver : public NPC
{
private:
    void showOptions(void) override;
    virtual void interprateChoice(int choice, Player *pc) override;

public:
    void getUserToChoseOption(Player *pc) override;
    void giveQuest(Player *player);
    void giveRewardForQuest(Player *player, Quest *realisedQuest);
    void show() override;
    virtual ~NPCQuestGiver() override = default;
    NPCQuestGiver() =default;
};

#endif // NPC_H