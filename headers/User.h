/***********************************************************************
 * Module:  User.h
 * Author:  franc
 * Modified: niedziela, 4 stycznia 2026 15:16:58
 * Purpose: Declaration of the class User
 ***********************************************************************/

#ifndef __UMLClassDiagram_1_User_h
#define __UMLClassDiagram_1_User_h

class Voteings;
class UserGroup;
class Event;
#include "Post.h"
#include "Event.h"
#include "UserGroup.h"


class User
{
protected:
   int amountOfLogins;
   deque<string> notifications;
   vector<User *> friendsList;
   vector<Post *> postList;
   vector<UserGroup *> userGroups;
   list<Event *> events;
   list<Voteings *> votings;
   void * pictureLink;// for now unused

public:
   void createGroup(void);
   void createPost(string contetns);
   void createPost(UserGroup *groupInWichToPost,string contents);

   void addUserToFriendsList(User *newFriend);
   void removeUserFromFriendsList(User *exFriend);
   void reportPostToAdmin(Post * reportedPost,User * admin);
   
   virtual void voteInPoll(void);
   void createPool();

   virtual void deleteGroup(void);
   virtual void addUserToGroup(UserGroup *group, User *userToAdd);
   virtual void deleteActivity(Post *activity); //  gives true on sucess and false on failure
    //used to delete post from specific group where user is a admin or tries to exicse admin
    // privlges
   virtual void deleteActivity(Post *acticity, UserGroup *wheretoDeketeFrom);
   virtual void removeUserFromGroup(void);

   // Not Implemented:
   void setNotificationsPrefences(void);
   void readNotification(void);
   bool setVisbiltyForPost(Post *post);
   void flirtPostsBy(void);

};

#endif