/***********************************************************************
 * Module:  NPCTrader.h
 * Author:  franc
 * Modified: poniedzia³ek, 26 stycznia 2026 17:02:26
 * Purpose: Declaration of the class NPCTrader
 ***********************************************************************/

#if !defined(__UMLClassDiagram_1_NPCTrader_h)
#define __UMLClassDiagram_1_NPCTrader_h

#include <NPC.h>

class NPCTrader : public NPC
{
public:
   void sellItem(void);
   void buyItem(void);
   void giveSelection(void);

protected:
private:
   int listOfItems;


};

#endif