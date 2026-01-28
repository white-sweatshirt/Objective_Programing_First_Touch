#include "NPC.h"
#include "ActiveActor.h"
#include "Player.h"
#include "Quest.h"
void NPC::giveOptionsInDialogue()
{
    std::cout << "I am just poor NPC I have no purpouse <<ins"
              << "ert inteligent one liner>>" << std::endl;
}
void NPC::show()
{
    std::cout << "Jestem " << this->name;
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
