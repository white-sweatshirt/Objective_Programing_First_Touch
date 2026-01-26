/***********************************************************************
 * Module:  NPC.h
 * Author:  franc
 * Modified: poniedzia³ek, 26 stycznia 2026 19:36:49
 * Purpose: Declaration of the class NPC
 ***********************************************************************/

#if !defined(__UMLClassDiagram_1_NPC_h)
#define __UMLClassDiagram_1_NPC_h

class Items;

class NPC
{
public:
   void dogeAttacks(void);

   Items** items;

protected:
private:
   int Attribute_2;


};

#endif