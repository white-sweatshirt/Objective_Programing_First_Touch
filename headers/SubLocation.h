/***********************************************************************
 * Module:  SubLocation.h
 * Author:  franc
 * Modified: poniedzia�ek, 26 stycznia 2026 19:54:42
 * Purpose: Declaration of the class SubLocation
 ***********************************************************************/

#ifndef PLACE_OF_IMPORTANCE_H
#define PLACE_OF_IMPORTANCE_H
#include "NPC.h"

class ActiveActor;

class SubLocation
{
private:
    ActiveActor* enemy ;
    NPC* interestingNPC;
    std::string description;

public:
    void show(); 
    ActiveActor * giveAntagonist(void);
    void setOponent(ActiveActor *opponet);
    void setNPC(NPC *npc);
    void setdesc(std::string desc);
    SubLocation(ActiveActor *opponent, NPC *npc,std::string desc);
    SubLocation(ActiveActor *opponent, NPC *npc);
    NPC* giveNPC(void);
};

#endif