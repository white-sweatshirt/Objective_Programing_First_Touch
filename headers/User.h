/***********************************************************************
 * Module:  User.h
 * Author:  franc
 * Modified: niedziela, 4 stycznia 2026 15:16:58
 * Purpose: Declaration of the class User
 ***********************************************************************/

#ifndef __UMLClassDiagram_1_User_h
#define __UMLClassDiagram_1_User_h
#include "Events.h"
#include "Post.h"
#include "User.h"
#include "userGroup.h"
class UserGroup;
class User
{
protected:
   short photos;
   int amountOfLogins;
   deque <string> notifications;
   vector<User *> friendsList;
   vector<Post *> postList;
   vector<UserGroup *> userGroups;
   list<Events *> events;
   list<Voteings *> votings;

public:
   void createGroup(void);
   void createPost(void);
   void postToo(void);

   virtual void voteInPoll(void);
   Voteings *createPool();

   virtual bool deleteGroup(void);
   virtual bool addUserToGroup(UserGroup * group,User * userToAdd);
   virtual void deleteActivity(Post * activity);
   virtual int removeUserFromGroup(void);

   void readNotification(void);
   bool setVisbiltyForPost(Post * post);
};

#endif