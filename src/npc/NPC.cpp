#include "NPC.h"
#include "ActiveActor.h"
#include "Player.h"
#include "Quest.h"
#include "TemplateLib.h"
void NPC::show()
{
    std::cout << "Jestem " << this->name;
}
void NPC::askForUserInput()
{
}
void NPC::showOptions()
{
}

void NPC::getUserToChoseOption(Player *cp)
{
}
void NPCHealer::showOptions(void)
{
    std::cout << "0. ulecz postac" << std::endl;
    std::cout << "1. zakoncz interakcje" << std::endl;
}
void NPCHealer::interprateChoice(int choice, Player *pc)
{
    switch (choice)
    {
    case 0:
        this->healPlayerForFee(pc);
        break;
    case 1:
        break;
    default:
        break;
    }
}

void NPCHealer::getUserToChoseOption(Player *pc)
{
    interprateChoice(templateLib::getStandardChoiceResult(this, showOptions, 0, 1), pc);
}

void NPCHealer::show()
{
    std::cout << "jestem healerm" << std::endl;
}

void NPCHealer::healPlayerForFee(ActiveActor *pCharacter)
{
    if (!pCharacter)
        return;

    if (pCharacter->payForSth(this->healingFee))
    {
        // friend clausere in use
        pCharacter->hP = pCharacter->maxHp;
        std::cout << "Healing successful. HP fully restored." << std::endl;
    }
    else
        std::cout << " Hero is too poor to afford healing." << std::endl;
}
void NPCQuestGiver::showOptions(void)
{
    std::cout << "0. Popros o newego questa w ramach ktorego zabijesz kilku nieprzyjaciol" << std::endl;
    std::cout << "1. popros o quest typu zbierz kilka itemkow" << std::endl;
    std::cout << "2. odbierz nagrode za zrealizowane questy" << std::endl;
    std::cout << "3. zakoncz rozmowe" << std::endl;
}
void NPCQuestGiver::interprateChoice(int choice, Player *pc)
{

    switch (choice)
    {
    case 0:
        pc->receiveQuest(new KillingQuest(rand() % 4 + 1));
        break;
    case 1:
        pc->receiveQuest(new SearchQuest(rand() % 3 + 1));
    case 2:
        pc->fullfillQuests(this);
    default:
        break;
    }
}
void NPCQuestGiver::getUserToChoseOption(Player *pc)
{
    interprateChoice(templateLib::getStandardChoiceResult(this,showOptions,0,2),pc);
}
void NPCQuestGiver::show()
{
    std::cout<<"jestem npc dajacym questy jestem: "<<this->name<<std::endl;
}
void NPCQuestGiver::giveRewardForQuest(Player *player, Quest *realisedQuest)
{
    if (!player || !realisedQuest)
        return;
    if (realisedQuest->checkFulfillmentCondition())
        player->getMonetaryReward(realisedQuest->giveReward());
}
void NPCQuestGiver::giveQuest(Player *player)
{
    player->receiveQuest(new KillingQuest());
}
