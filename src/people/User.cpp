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
   if(reportedPost == nullptr || admin == nullptr)
      return;
   // perfect world in with reported post are aloweys truthly reoprted
   admin->deleteActivity(reportedPost);
}
UserGroup * User::giveGroupLink(int indexOfGroup)
{
   if (indexOfGroup < 0 || indexOfGroup >= userGroups.size())
      return nullptr;
   return userGroups[indexOfGroup];
}
void User::joinGroup(UserGroup *groupToJoin)
{
   groupToJoin->addPersonToGroup(this);
}

void User::createPost(string contetns)
{
   ownedPosts.push_back(new Post(this, contetns));
}

void User::createPost(UserGroup *groupInWichToPost, string contents)
{
   ownedPosts.push_back(new Post(this, contents));
   groupInWichToPost->addPostToGroup(ownedPosts.back());
}
void User::createEvent(Event *newEvent)
{
   events.push_back(newEvent);
}
void User::createEvent(UserGroup *groupInWichToCreateEvent, Event *newEvent)
{
   events.push_back(newEvent);
   groupInWichToCreateEvent->addEventToGroup(newEvent);
}
void User::joinEvent(Event *eventToJoin)
{
   eventToJoin->addParticipant(this);
}
void User::createVoting(Voteings *newVoting)
{
   votings.push_back(newVoting);
}
void User::createVoting(UserGroup *groupInWichToCreateVoting, Voteings *newVoting)
{
   votings.push_back(newVoting);
   groupInWichToCreateVoting->addVotingToGroup(newVoting);
}
void User::removeUserFromFriendsList(User *exFriend)
{
   killElementOfVector(friendsList, exFriend);
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

void User::deleteActivity(Post *postToDelete)
{
   if (postToDelete)
      if (postToDelete->checkWheterPersonIsOwner(this))
         delete postToDelete;
}

void User::deleteActivity(Post *postToDelete, UserGroup *groupOnWithItIsPosted)
{
   if (postToDelete == nullptr || groupOnWithItIsPosted == nullptr)
      return;
   if (postToDelete->checkWheterPersonIsOwner(this))
      delete postToDelete;
   else if (groupOnWithItIsPosted->checkIfUserHasPremissonToDelete(this, postToDelete))
      delete postToDelete;
}
void User::removeUserFromGroup(void)
{
   // TODO : implement
}

void User::voteInPoll(void)
{
   // TODO : implement
}

void User::deleteGroup(void)
{
   // TODO : implement
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