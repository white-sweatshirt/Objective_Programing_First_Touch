#include "SubLocation.h"
#include <iostream>
#include "ActiveActor.h"
void SubLocation::show() 
{
    std::cout << "Sublokacja : " << description << std::endl;
    if (interestingNPC)
    {
        std::cout << "NPC jest obecny: " << std::endl;
        this->interestingNPC->show();
    }
    if (enemy)
    {
        std::cout << "Przeciwnik jest obecny .\nInformacje na jego temat:" << std::endl;
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
SubLocation::SubLocation(ActiveActor *opponent,std::string desc):
enemy(opponent),description(desc)
{
    this->interestingNPC=nullptr;
}
SubLocation::SubLocation(NPC *npc,std::string desc):
interestingNPC(npc),description(desc)
{
    this->enemy=nullptr;
}

NPC * SubLocation::giveNPC(void)
{
    return this->interestingNPC;
}
ActiveActor * SubLocation::giveAntagonist(void)
{
    return this->enemy;
}
SubLocation::~SubLocation(void)
{
    if(enemy)
        delete enemy;
    if(interestingNPC)
        delete interestingNPC;
}
