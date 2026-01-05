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
   bool veryfiyAdminPrivilges(User *personToVerify);

public:
   // bool in functions is meant to
   // represent failure of suceess of action
   bool addPersonToNotyfications(User *personToAdd);
   void removePersonFromNotfications(User *personToRemove);
   void addPersonToGroup(User *personToAdd);
   bool removePersonFromGroup(User *personToRemove, User *requestingUser);

   void removePostFromGroupMemory(Post *post);
   void addPostToGroup(Post *post);
   void addEventToGroup(Event *event);
   void addVotingToGroup(Voteings *voting);
   bool checkIfUserHasPremissonToDelete(User *userRequestingDeletion, Post *postToDelete);

   bool addAdmin(void);
   UserGroup(User *creator);
};

#endif