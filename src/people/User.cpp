/***********************************************************************
 * Module:  User.cpp
 * Author:  WhiteSweatShirt
 * Modified: niedziela, 4 stycznia 2026 15:16:58
 * Purpose: Implementation of the class User
 ***********************************************************************/
#include "User.h"

void User::createGroup(void)
{
   // TODO : implement
}


void User::createPost(string contetns)
{
   postList.push_back(new Post(this, contetns));
}

void User::createPost(UserGroup *groupInWichToPost, string contents)
{
   postList.push_back(new Post(this, contents));
   groupInWichToPost->addPostToGroup(postList.back());
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


}

bool User::deleteActivity(Post * activityToDelete,UserGroup *groupOnWithItIsPosted)
{

}
void  User::removeUserFromGroup(void)
{
   // TODO : implement
}


void User::voteInPoll(void)
{
   // TODO : implement
}


bool User::deleteGroup(void)
{
   // TODO : implement
}


bool User::addUserToGroup(UserGroup *group, User *userToAdd)
{
  
}