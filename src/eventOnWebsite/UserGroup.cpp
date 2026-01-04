/***********************************************************************
 * Module:  UserGroup.cpp
 * Author:  franc
 * Modified: niedziela, 4 stycznia 2026 15:05:54
 * Purpose: Implementation of the class UserGroup
 ***********************************************************************/
#include "UserGroup.h"

bool UserGroup::veryfiyAdminPrivilges(User *personToVerify)
{
   for (auto member : this->membersOfGroup)
      if (member->giveUserPointer() == personToVerify)
         return member->sayIfUserIsAdmin();
   return false;
}

bool UserGroup::addPersonToGroup(User *personToAdd)
{
   this->membersOfGroup.push_back(new MemberOfGroup(personToAdd, false));
   this->numberOfMembers++;
}

void UserGroup::removePersonFromNotfications(User *personToRemove)
{
   for (auto w : this->notificationsList)
   {
      if (w == personToRemove)
      {
         this->notificationsList.remove(w);
         return;
      }
   }
}
Post *UserGroup::checkIfPostExitsts(Post *post)
{
   for (auto checkedPost : this->postLists)
      if (checkedPost == post)
         return checkedPost;
   return nullptr;
}
bool UserGroup::removePersonFromGroup(void)
{
   // TODO : implement
}

void UserGroup::deletePost(User *userRequestingDeletion, Post *postToDelete)
{
   if (!checkIfPostExitsts(postToDelete))
      return;
   if (!userRequestingDeletion->deleteActivity(postToDelete))
      if (veryfiyAdminPrivilges(userRequestingDeletion))
         delete postToDelete;
}

Event* UserGroup::createEvent(void)
{
   
}

void UserGroup::createVoting(void)
{
   // TODO : implement
}

bool UserGroup::addAdmin(void)
{
   // TODO : implement
}

int UserGroup::veryfiyIfThereAnyAdmins(void)
{
   // TODO : implement
}
UserGroup::UserGroup(User *creator)
{
   this->numberOfMembers = 1;
   this->membersOfGroup.push_back(new MemberOfGroup(creator, true));
}