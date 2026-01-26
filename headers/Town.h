/***********************************************************************
 * Module:  Town.h
 * Author:  franc
 * Modified: poniedzia³ek, 26 stycznia 2026 19:51:10
 * Purpose: Declaration of the class Town
 ***********************************************************************/

#if !defined(__UMLClassDiagram_1_Town_h)
#define __UMLClassDiagram_1_Town_h

#include <Location.h>

class Town : public Location
{
public:
protected:
private:
   vecto<NPC*> vectorOfNPCs;


};

#endif