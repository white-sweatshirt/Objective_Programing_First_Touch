/***********************************************************************
 * Module:  User.h
 * Author:  franc
 * Modified: niedziela, 4 stycznia 2026 15:16:58
 * Purpose: Declaration of the class User
 ***********************************************************************/

#ifndef __UMLClassDiagram_1_User_h
#define __UMLClassDiagram_1_User_h
#include "Event.h"
#include "Post.h"
#include "User.h"
#include "userGroup.h"
class UserGroup;
class User
{
protected:
   int amountOfLogins;
   deque <string> notifications;
   vector<User *> friendsList;
   vector<Post *> postList;
   vector<UserGroup *> userGroups;
   list<Event *> events;
   list<Voteings *> votings;

public:
   void createGroup(void);
   void createPost(void);
   void postToo(void);

   void addUserToFriendsList(User * newFriend);
   void removeUserFromFriendsList(User * exFriend);

   virtual void voteInPoll(void);
   Voteings *createPool();

   virtual bool deleteGroup(void);
   virtual bool addUserToGroup(UserGroup * group,User * userToAdd);
   virtual bool deleteActivity(Post * activity);// bool gives sucessful delition or not
   virtual int removeUserFromGroup(void);

   void readNotification(void);
   bool setVisbiltyForPost(Post * post);
};

#endif