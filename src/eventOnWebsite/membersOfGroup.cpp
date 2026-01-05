/***********************************************************************
 * Module:  MemberOfGroup.cpp
 * Author:  WhiteSweatShirt
 * Modified: niedziela, 4 stycznia 2026 15:06:52
 * Purpose: Implementation of the class MemberOfGroup
 ***********************************************************************/

#include "MemberOfGroup.h"

User *MemberOfGroup::giveUserPointer(void)
{
   return this->user;
}
bool MemberOfGroup::sayIfUserIsAdmin(void)
{
   return (this->adminPrivileges == true) ? true : false;
}
MemberOfGroup::MemberOfGroup(User *user, bool giveAdminPrivilges)
{
   this->user=user;
   this->adminPrivileges=giveAdminPrivilges;
}