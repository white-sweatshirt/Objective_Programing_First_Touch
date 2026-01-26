/***********************************************************************
 * Module:  PlaceOFImportance.h
 * Author:  franc
 * Modified: poniedzia³ek, 26 stycznia 2026 19:54:42
 * Purpose: Declaration of the class PlaceOFImportance
 ***********************************************************************/

#if !defined(__UMLClassDiagram_1_PlaceOFImportance_h)
#define __UMLClassDiagram_1_PlaceOFImportance_h

#include <ActiveActor.h>
#include <NPC.h>

class PlaceOFImportance
{
public:
   void giveOption(void);

protected:
private:
   ActiveActor * interestingOppone;
   NPC * interestingNPC;
   string whatIsInteresting;


};

#endif