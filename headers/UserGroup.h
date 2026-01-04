/***********************************************************************
 * Module:  UserGroup.h
 * Author:  WhiteSweatShirt
 * Modified: niedziela, 4 stycznia 2026 15:05:54
 * Purpose: Declaration of the class UserGroup
 ***********************************************************************/

#ifndef __UMLClassDiagram_1_UserGroup_h
#define __UMLClassDiagram_1_UserGroup_h

#include "Post.h"
#include "Event.h"
#include "MemberOfGroup.h"
#include <deque>
class Event;
class MemberOfGroup;
class Voteings;
class Post;

class UserGroup
{

private:
   int numberOfMembers;
   list<Event *> eventsInGroup; // to do implement events data structure
   vector<MemberOfGroup *> membersOfGroup;
   deque<Voteings *> votings;
   deque<Post *> postLists;
   list<User *> notificationsList;
   Post *checkIfPostExitsts(Post *post);
   bool veryfiyAdminPrivilges(User *personToVerify);

public:
   // bool in functions is meant to
   // represent failure of suceess of action
   bool addPersonToNotyfications(User *personToAdd);
   void removePersonFromNotfications(User *personToRemove);
   bool addPersonToGroup(User *personToAdd);
   bool removePersonFromGroup(void);

   Post *createPost(void);
   Event *createEvent(void);
   Voteings *createVoting(void);
   void deletePost(User *userRequestingDeletion, Post *postToDelete);

   bool addAdmin(void);
   int veryfiyIfThereAreAnyAdmins(void);
   UserGroup(User *creator);
};

#endif