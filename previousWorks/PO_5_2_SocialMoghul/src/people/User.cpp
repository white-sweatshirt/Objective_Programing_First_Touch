/***********************************************************************
 * Module:  User.cpp
 * Author:  WhiteSweatShirt
 * Modified: niedziela, 4 stycznia 2026 15:16:58
 * Purpose: Implementation of the class User
 ***********************************************************************/
#include "User.h"

void User::createGroup(void)
{
   userGroups.push_back(new UserGroup(this));
}
void User::reportPostToAdmin(Post *reportedPost, User *admin)
{
   if (reportedPost == nullptr || admin == nullptr)
      return;
   // perfect world in with reported post are aloweys truthly reoprted
   admin->deleteActivity(reportedPost);
}
UserGroup *User::giveGroupLink(int indexOfGroup)
{
   if (userGroups.empty())
      return nullptr;
   if (indexOfGroup < 0 || indexOfGroup >= userGroups.size())
      return nullptr;
   return userGroups[indexOfGroup];
}
void User::joinGroup(UserGroup *groupToJoin)
{
   if (groupToJoin == nullptr)
      return;
   groupToJoin->addPersonToGroup(this);
   this->userGroups.push_back(groupToJoin);
}
void User::leaveGroup(UserGroup *groupToLeave)
{
   if (groupToLeave)
   {
      removeElemetOfVector(this->userGroups, groupToLeave);
      removeUserFromGroup(this, this, groupToLeave);
   }
}
void User::post(Post *newPost)
{
   if (newPost == nullptr)
      return;
   ownedPosts.push_back(newPost);
}

void User::post(UserGroup *groupInWichToPost, Post *newPost)
{
   if (newPost == nullptr || groupInWichToPost == nullptr)
      return;
   ownedPosts.push_back(newPost);
   groupInWichToPost->addPostToGroup(newPost);
   ownedPosts.back()->setGroupAssociation(groupInWichToPost);
}

void User::createEvent(Event *newEvent)
{
   if (newEvent == nullptr)
      return;
   events.push_back(newEvent);
}
void User::createEvent(UserGroup *groupInWichToCreateEvent, Event *newEvent)
{
   if (newEvent == nullptr || groupInWichToCreateEvent == nullptr)
      return;
   events.push_back(newEvent);
   if (groupInWichToCreateEvent->verifyMemberShip(this))
      groupInWichToCreateEvent->addEventToGroup(newEvent);
}
void User::joinEvent(Event *eventToJoin)
{
   if (eventToJoin == nullptr)
      return;
   eventToJoin->addParticipant(this);
}
void User::createVoting(Voteings *newVoting)
{
   if (newVoting == nullptr)
      return;
   votings.push_back(newVoting);
}
void User::createVoting(UserGroup *groupInWichToCreateVoting, Voteings *newVoting)
{
   if (newVoting == nullptr)
      return;
   votings.push_back(newVoting);
   groupInWichToCreateVoting->addVotingToGroup(newVoting);
}
void User::removeUserFromFriendsList(User *exFriend)
{
   if (exFriend == nullptr)
      return;
   removeElemetOfVector(friendsList, exFriend);
}
void User::showAllEventsInGroup(UserGroup *group)
{
   if (group)
      group->showAllEventsInGroup();
}
void User::showAllPostsInGroup(UserGroup *group)
{
   if (group)
      group->showAllPostsInGroup();
}
void User::showAllVotingsInGroup(UserGroup *group)
{
   if (group)
      group->showAllVotingsInGroup();
}
Post *User::givePostLink(int indexOfPost)
{
   if (indexOfPost < 0 || indexOfPost >= ownedPosts.size())
      return nullptr;
   return ownedPosts[indexOfPost];
}
void User::removePostFromOwnedPosts(Post *postToRemove)
{
   if (postToRemove)
      removeElemetOfVector(ownedPosts, postToRemove);
}
void User::show()
{
   std::cout << "User name: " << this->name << std::endl;
}
User::~User()
{
   killVectorOfPointers(this->ownedPosts);
   for (auto w : this->userGroups)
      if (w->veryfiyAdminPrivilges(this))
         delete w;
      else
         w->removePersonFromGroup(this);

   friendsList.clear();
   for (auto w : this->events)
      if (!deleteActivity(w))
         w->removePersonFromParticipants(this);
   for (auto w : this->votings)
      deleteActivity(w);
}
void User::readNotification(void)
{
   // TODO : implement
}

void User::flirtPostsBy(void)
{
   // TODO : implement
}

void User::setNotificationsPrefences(void)
{
   // TODO : implement
}

bool User::deleteActivity(Post *postToDelete)
{
   if (postToDelete)
      if (postToDelete->checkWheterPersonIsOwner(this))
      {
         delete postToDelete;
         return true;
      }
   return false;
}

bool User::deleteActivity(Post *postToDelete, UserGroup *groupOnWithItIsPosted)
{
   if (postToDelete == nullptr || groupOnWithItIsPosted == nullptr)
      return false;
   if (postToDelete->checkWheterPersonIsOwner(this))
   {
      delete postToDelete;
      return true;
   }
   else if (groupOnWithItIsPosted->veryfiyAdminPrivilges(this))
   {
      delete postToDelete;
      return true;
   }
   return false;
}
void User::removeUserFromGroup(User *userToRemove, User *requestingUser, UserGroup *group)
{
   if (this->userGroups.size() == 0)
      return;
   if (group == nullptr || userToRemove == nullptr || requestingUser == nullptr)
      return;
   if (group->veryfiyAdminPrivilges(requestingUser) || userToRemove == requestingUser)
      group->removePersonFromGroup(userToRemove);
}

void User::voteInPoll(void)
{
   // TODO : implement
}

void User::deleteGroup(UserGroup *groupToDelete)
{
   if (groupToDelete && groupToDelete->veryfiyAdminPrivilges(this))
      delete groupToDelete;
}

void User::addUserToGroup(UserGroup *group, User *userToAdd)
{
   if (group == nullptr || userToAdd == nullptr)
      return;
   group->addPersonToGroup(userToAdd);
}

string User::giveName(void)
{
   return this->name;
}
void User::addUserToFriendsList(User *newFriend)
{
   friendsList.push_back(newFriend);
}
User::User(string name)
{
   this->name = name;
   this->amountOfLogins = 0;
}