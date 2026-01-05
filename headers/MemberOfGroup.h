/***********************************************************************
 * Module:  membersOfGroup.h
 * Author:  WhiteSweatShirt
 * Modified: niedziela, 4 stycznia 2026 15:06:52
 * Purpose: Declaration of the class membersOfGroup
 ***********************************************************************/

#ifndef __UMLClassDiagram_1_membersOfGroup_h
#define __UMLClassDiagram_1_membersOfGroup_h
#include "User.h"
class MemberOfGroup
{
private:
   bool adminPrivileges;
   User *user;
public:
   User *giveUserPointer(void);
   bool sayIfUserIsAdmin(void);
   MemberOfGroup * givePointerToMember(User *user);
   void giveAdminPrivilges();
   MemberOfGroup(User*user,bool giveAdminPrivilges);
};

#endif