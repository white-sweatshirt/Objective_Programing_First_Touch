/***********************************************************************
 * Module:  UserGroup.h
 * Author:  WhiteSweatShirt
 * Modified: niedziela, 4 stycznia 2026 15:05:54
 * Purpose: Declaration of the class UserGroup
 ***********************************************************************/

#ifndef __UMLClassDiagram_1_UserGroup_h
#define __UMLClassDiagram_1_UserGroup_h

class Events;
class membersOfGroup;
class Votings;
class Post;

class UserGroup
{
public:
   bool veryfiyAdminPrivilges(void);
   bool addPersonToGroup(void);
   void removePersonFromNotfications(void);
   bool removePersonFromGroup(void);
   void deletePost(void);
   void createEvent(void);
   void createVoting(void);
   bool addAdmin(void);
   int veryfiyIfThereAnyAdmins(void);

   Events** events;
   membersOfGroup** membersOfGroup;
   Votings** votings;

protected:
private:
   int members;
   
   Post** post;


};

#endif