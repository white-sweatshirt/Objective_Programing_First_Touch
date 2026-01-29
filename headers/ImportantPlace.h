/***********************************************************************
 * Module:  PlaceOFImportance.h
 * Author:  franc
 * Modified: poniedzia�ek, 26 stycznia 2026 19:54:42
 * Purpose: Declaration of the class PlaceOFImportance
 ***********************************************************************/

#ifndef PLACE_OF_IMPORTANCE_H
#define PLACE_OF_IMPORTANCE_H
#include "NPC.h"

class ActiveActor;

class PlaceOFImportance
{
private:
    ActiveActor* enemy ;
    NPC* interestingNPC;
    std::string description;

public:
    void giveOption(void);
    void show() const; // Method to display details of the place
    ActiveActor * giveAntagonist(void);
    NPC* giveNPC(void);
};

#endif