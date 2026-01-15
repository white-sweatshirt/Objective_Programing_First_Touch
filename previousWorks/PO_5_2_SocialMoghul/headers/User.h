/***********************************************************************
 * Module:  User.h
 * Author:  WhiteSweatShirt
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
#include "TemplateLib.h"

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
   void joinGroup(UserGroup *groupToJoin);
   void leaveGroup(UserGroup *groupToLeave);

   void removePostFromOwnedPosts(Post *postToRemove);
   void post(Post *newPost);
   void post(UserGroup *groupInWichToPost, Post *newPost);
   void createEvent(Event *newEvent);
   void createEvent(UserGroup *groupInWichToCreateEvent, Event *newEvent);
   void joinEvent(Event *eventToJoin);
   void createVoting(Voteings *newVoting);
   void createVoting(UserGroup *groupInWichToCreateVoting, Voteings *newVoting);
   virtual void voteInPoll(void);
   Post *givePostLink(int indexOfPost);

   void showAllPostsInGroup(UserGroup *group);
   void showAllEventsInGroup(UserGroup *group);
   void showAllVotingsInGroup(UserGroup *group);

   void addUserToFriendsList(User *newFriend);
   void removeUserFromFriendsList(User *exFriend);
   void reportPostToAdmin(Post *reportedPost, User *admin);

   virtual UserGroup *giveGroupLink(int indexOf);
   virtual void deleteGroup(UserGroup *groupToDelete);
   virtual void addUserToGroup(UserGroup *group, User *userToAdd);
   virtual bool deleteActivity(Post *activity);
   virtual void show();
   // used to delete post from specific group where user is a admin
   // or tries to exicse admin
   // privileges
   virtual bool deleteActivity(Post *acticity, UserGroup *wheretoDeketeFrom);
   virtual void removeUserFromGroup(User *userToRemove, User *requestingUser, UserGroup *group);
   User(string name);

   string giveName(void);
   // Not Implemented:
   void setNotificationsPrefences(void);
   void readNotification(void);
   bool setVisbiltyForPost(Post *post);
   void flirtPostsBy(void);
   ~User();
};

#endif