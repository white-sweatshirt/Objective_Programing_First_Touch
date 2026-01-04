/***********************************************************************
 * Module:  UserGroup.h
 * Author:  WhiteSweatShirt
 * Modified: niedziela, 4 stycznia 2026 15:05:54
 * Purpose: Declaration of the class UserGroup
 ***********************************************************************/

#ifndef __UMLClassDiagram_1_UserGroup_h
#define __UMLClassDiagram_1_UserGroup_h

#include "Post.h"
#include "Events.h"
#include "MemberOfGroup.h"
#include <deque>
class Events;
class MemberOfGroup;
class Voteings;
class Post;

class UserGroup
{

private:
   int members;
   list<Events *> eventsInGroup; // to do implement events data structure
   vector<MemberOfGroup *> membersOfGroup;
   deque<Voteings *> votings;
   deque<Post *> post;

public:
   // bool in functions is meant to
   // represent failure of suceess of action
   bool addPersonToNotyfications(User *personToAdd);
   bool removePersonFromNotfications(void);
   bool addPersonToGroup(void);
   bool removePersonFromGroup(void);

   Post *createPost(void);
   Events *createEvent(void);
   Voteings *createVoting(void);
   bool deletePost(void);

   bool veryfiyAdminPrivilges(void);
   bool addAdmin(void);
   int veryfiyIfThereAreAnyAdmins(void);
};

#endif