/***********************************************************************
 * Module:  membersOfGroup.h
 * Author:  WhiteSweatShirt
 * Modified: niedziela, 4 stycznia 2026 15:06:52
 * Purpose: Declaration of the class membersOfGroup
 ***********************************************************************/

#ifndef __UMLClassDiagram_1_membersOfGroup_h
#define __UMLClassDiagram_1_membersOfGroup_h

class membersOfGroup
{
public:
   void* checkWheterUserIsMember(void);
   bool sayIfUserIsAdmin(void);

protected:
private:
   bool aminPrivliges;


};

#endif