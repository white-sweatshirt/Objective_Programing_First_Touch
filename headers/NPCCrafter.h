/***********************************************************************
 * Module:  NPCCrafter.h
 * Author:  franc
 * Modified: poniedzia³ek, 26 stycznia 2026 20:12:39
 * Purpose: Declaration of the class NPCCrafter
 ***********************************************************************/

#if !defined(__UMLClassDiagram_1_NPCCrafter_h)
#define __UMLClassDiagram_1_NPCCrafter_h

#include <NPCTrader.h>

class NPCCrafter : public NPCTrader
{
public:
   void createItem(void);
   void destroyItem(void);

protected:
private:
   double createItem;
   double destroyItem;


};

#endif