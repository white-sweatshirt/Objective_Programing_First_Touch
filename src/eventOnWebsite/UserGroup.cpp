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
   {
      if (member->giveUserPointer() == personToVerify)
      {
         return member->sayIfUserIsAdmin();
      }
   }
   return false;
}

void UserGroup::addPersonToGroup(User *personToAdd)
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
bool UserGroup::removePersonFromGroup(User *personToRemove, User *requestingUser)
{
   if (veryfiyAdminPrivilges(requestingUser) || personToRemove == requestingUser)
      return false;
   for (auto checkedMember : membersOfGroup)
   {
      if (checkedMember->giveUserPointer() == personToRemove)
      {
         swap(this->membersOfGroup.back(), checkedMember);
         this->membersOfGroup.pop_back();
         this->numberOfMembers--;
         return true;
      }
   }
   return false;
}
void UserGroup::removePostFromGroupMemory(Post *postToRemove)
{
   this->postLists.remove(postToRemove);
}
bool UserGroup::checkIfUserHasPremissonToDelete(User *userRequestingDeletion,
                                                Post *postToDelete)
{
   if(this->veryfiyAdminPrivilges(userRequestingDeletion))
      return true;
   else
      return false;
}
void UserGroup::addPostToGroup(Post *post)
{
   this->postLists.push_back(post);
}
void UserGroup::addEventToGroup(Event *event)
{
   this->eventsInGroup.push_back(event);
}

void UserGroup::addVotingToGroup(Voteings *voting)
{
   this->votings.push_back(voting);
}

bool UserGroup::addAdmin(void)
{
   // TODO : implement
}

UserGroup::UserGroup(User *creator)
{
   this->numberOfMembers = 1;
   this->membersOfGroup.push_back(new MemberOfGroup(creator, true));
}