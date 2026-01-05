/***********************************************************************
 * Module:  User.h
 * Author:  franc
 * Modified: niedziela, 4 stycznia 2026 15:16:58
 * Purpose: Declaration of the class User
 ***********************************************************************/

#ifndef __UMLClassDiagram_1_User_h
#define __UMLClassDiagram_1_User_h
class Event;
class Post;
class UserGroup;
class Voteings;
#include "UserGroup.h"
template <typename vectorOfPointersToClass, typename pointerTypeToRemove >
void killElementOfVector(vectorOfPointersToClass & a,pointerTypeToRemove);

template <typename vectorOfPointers>
void killVectorOfPointers(vectorOfPointers & killedVector);

class User
{
protected:
   int amountOfLogins;
   string name;
   deque<string> notifications;
   vector<User *> friendsList;
   vector<Post *> ownedPosts;
   vector<UserGroup *> userGroups;
   list<Event *> events;
   list<Voteings *> votings;
   void *pictureLink; // for now unused

public:
   void createGroup(void);
   void createPost(string contetns);
   void createPost(UserGroup *groupInWichToPost, string contents);
   void joinGroup(UserGroup *groupToJoin);
   
   void addUserToFriendsList(User *newFriend);
   void removeUserFromFriendsList(User *exFriend);
   void reportPostToAdmin(Post *reportedPost, User *admin);

   virtual void voteInPoll(void);
   void createPool();
   virtual UserGroup * giveGroupLink(int indexOf);
   virtual void deleteGroup(void);
   virtual void addUserToGroup(UserGroup *group, User *userToAdd);
   virtual void deleteActivity(Post *activity);
   // used to delete post from specific group where user is a admin
   // or tries to exicse admin
   // privlges
   virtual void deleteActivity(Post *acticity, UserGroup *wheretoDeketeFrom);
   virtual void removeUserFromGroup(void);
   string giveName(void);
   // Not Implemented:
   void setNotificationsPrefences(void);
   void readNotification(void);
   bool setVisbiltyForPost(Post *post);
   void flirtPostsBy(void);
   User(string name);
};

#endif