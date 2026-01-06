/***********************************************************************
 * Module:  PlatformAdmin.cpp
 * Author:  WhiteSweatShirt
 * Modified: niedziela, 4 stycznia 2026 13:10:15
 * Purpose: Implementation of the class PlatformAdmin
 ***********************************************************************/

#include "PlatformAdmin.h"

void PlatformAdmin::lookThroughReports(void)
{
   // TODO : implement
}

void PlatformAdmin::blockAccount(void)
{
   // TODO : implement
}

void PlatformAdmin::removeAccount(void)
{
   // TODO : implement
}

bool PlatformAdmin::deleteActivity(Post *activity)
{
   if (activity)
   {
      delete activity;
      return true;
   }
   return false;
}

bool PlatformAdmin::deleteActivity(Post *acticity, UserGroup *wheretoDeketeFrom)
{
   if (acticity == nullptr || wheretoDeketeFrom == nullptr)
      return false;
   wheretoDeketeFrom->removePostFromGroupMemory(acticity);
   delete acticity;
   return true;
}
void PlatformAdmin::removeUserFromGroup(User *userToRemove, User *requestingUser, UserGroup *group)
{
   if (group == nullptr || userToRemove == nullptr || requestingUser == nullptr)
      return;
   group->removePersonFromGroup(userToRemove);
}
int PlatformAdmin::lookThroughStatistics(void)
{
   // TODO : implement
}
PlatformAdmin::PlatformAdmin(string name)
    : User(name)
{
}
void PlatformAdmin::deleteGroup(UserGroup *GroupToDelete)
{
   if (GroupToDelete)
      delete GroupToDelete;
}
void PlatformAdmin::show()
{
   cout << "I am Admin that is all you need to know!" << endl;
}