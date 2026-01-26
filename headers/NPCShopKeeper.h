/***********************************************************************
 * Module:  NPCShopKeeper.h
 * Author:  franc
 * Modified: poniedzia³ek, 26 stycznia 2026 19:34:07
 * Purpose: Declaration of the class NPCShopKeeper
 ***********************************************************************/

#if !defined(__UMLClassDiagram_1_NPCShopKeeper_h)
#define __UMLClassDiagram_1_NPCShopKeeper_h

#include <NPCTrader.h>

class NPCShopKeeper : public NPCTrader
{
public:
   void giveSelection(void);
   void sellItem(void);
   void buyItem(void);

protected:
private:

};

#endif