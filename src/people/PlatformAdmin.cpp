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

void PlatformAdmin::removePost(void)
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
}

void PlatformAdmin::deleteActivity(Post *acticity, UserGroup *wheretoDeketeFrom)
{
   wheretoDeketeFrom->removePostFromGroupMemory(acticity);
   
}

int PlatformAdmin::lookThroughStatistics(void)
{
   // TODO : implement
}
PlatformAdmin::PlatformAdmin(string name)
    : User(name)
{
}