#include "SubLocation.h"
#include <iostream>
#include "ActiveActor.h"
void SubLocation::show() 
{
    std::cout << "Interesting Place: " << description << std::endl;
    if (interestingNPC)
    {
        std::cout << "NPC present at this location." << std::endl;
        this->interestingNPC->show();
    }
    if (enemy)
    {
        std::cout << "Opponent present at this location.\n Importnat info:" << std::endl;
        this->enemy->giveVitalInfo();
    }
}
void SubLocation::setNPC(NPC *npc)
{
    delete this->interestingNPC;
    this->interestingNPC=npc;
}
void SubLocation::setdesc(std::string desc)
{
    this->description=desc;
}
void SubLocation::setOponent(ActiveActor * opponent)
{
    delete this->enemy;
    this->enemy= opponent;
}
SubLocation::SubLocation(ActiveActor *opponent, NPC *npc,std::string desc):
enemy(opponent), interestingNPC(npc), description(desc)
{
    
}
SubLocation::SubLocation(ActiveActor *opponent, NPC *npc)
: enemy(opponent), interestingNPC(npc)
{
    this->description="Test Arena location";
}
NPC * SubLocation::giveNPC(void)
{
    return this->interestingNPC;
}
ActiveActor * SubLocation::giveAntagonist(void)
{
    return this->enemy;
}

