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

void PlatformAdmin::deleteActivity(Post *activity)
{
   if (activity)
      delete activity;
}

void PlatformAdmin::deleteActivity(Post *acticity, UserGroup *wheretoDeketeFrom)
{
   wheretoDeketeFrom->removePostFromGroupMemory(acticity);
   delete acticity;
}

int PlatformAdmin::lookThroughStatistics(void)
{
   // TODO : implement
}
PlatformAdmin::PlatformAdmin(string name)
    : User(name)
{
}
void PlatformAdmin::show()
{
   cout << "I am Admin that is all you need to know!" << endl;
}