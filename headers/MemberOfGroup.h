/***********************************************************************
 * Module:  membersOfGroup.h
 * Author:  WhiteSweatShirt
 * Modified: niedziela, 4 stycznia 2026 15:06:52
 * Purpose: Declaration of the class membersOfGroup
 ***********************************************************************/

#ifndef __UMLClassDiagram_1_membersOfGroup_h
#define __UMLClassDiagram_1_membersOfGroup_h

class User;

#include "User.h"

class MemberOfGroup
{
private:
   bool adminPrivileges;
   User *user;

public:
   User *giveUserPointer(void);
   bool sayIfUserIsAdmin(void);
   void giveAdminPrivilges();
   MemberOfGroup(User *user, bool giveAdminPrivilges);
};

#endif