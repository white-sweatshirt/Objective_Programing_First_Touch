/***********************************************************************
 * Module:  Town.h
 * Author:  franc
 * Modified: poniedzia�ek, 26 stycznia 2026 19:51:10
 * Purpose: Declaration of the class Town
 ***********************************************************************/

#ifndef TOWN_H
#define TOWN_H

#include <Location.h>
#include <vector>
class NPC;
class Town : public Location
{
public:
protected:
private:
   std::vector<NPC*> vectorOfNPCs;

};
#include "NPC.h"
#endif