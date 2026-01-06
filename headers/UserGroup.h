/***********************************************************************
 * Module:  UserGroup.h
 * Author:  WhiteSweatShirt
 * Modified: niedziela, 4 stycznia 2026 15:05:54
 * Purpose: Declaration of the class UserGroup
 ***********************************************************************/

#ifndef __UMLClassDiagram_1_UserGroup_h
#define __UMLClassDiagram_1_UserGroup_h
class Event;
class Post;
class MemberOfGroup;
class Voteings;
#include "Event.h"
#include "MemberOfGroup.h"
#include "User.h"
class UserGroup
{

private:
   int numberOfMembers;
   list<Event *> eventsInGroup; // to do implement events data structure
   vector<MemberOfGroup *> membersOfGroup;
   deque<Voteings *> votings;
   list<Post *> postLists;
   list<User *> notificationsList;
   Post *checkIfPostExitsts(Post *post);

public:
   bool verifyMemberShip(User *personToVerify);
   bool veryfiyAdminPrivilges(User *personToVerify);
   // bool in functions is meant to
   // represent failure of suceess of action
   bool addPersonToNotyfications(User *personToAdd);
   void removePersonFromNotfications(User *personToRemove);
   void addPersonToGroup(User *personToAdd);
   bool removePersonFromGroup(User *personToRemove);

   void showAllPostsInGroup(void);
   void showAllEventsInGroup(void);
   void showAllVotingsInGroup(void);
   void show(void);

   void removePostFromGroupMemory(Post *post);
   void addPostToGroup(Post *post);
   void removeEventFromGroupMemory(Event *event);
   void addEventToGroup(Event *event);
   void removeVotingFromGroupMemory(Voteings *voting);
   void addVotingToGroup(Voteings *voting);

   bool addAdmin(void);
   UserGroup(User *creator);
   ~UserGroup();
};

#endif