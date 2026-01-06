/***********************************************************************
 * Module:  Post.h
 * Author:  WhiteSweatShirt
 * Modified: niedziela, 4 stycznia 2026 15:27:46
 * Purpose: Declaration of the class Post
 ***********************************************************************/

#ifndef __UMLClassDiagram_1_Post_h
#define __UMLClassDiagram_1_Post_h

// zasada przy urzywaniu programownia obiektowego zawsze deklaruj fowardowo
// wszystkie klasy z ktorych korzystarz we wszystkich
// plikach ktore pochodza od innego pliku

#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;
class User;
class UserGroup;
// meant to use with speciazlization of  Post class

class Post
// while using pointers to something always  use fowarding and do not do loops
{
protected:
   UserGroup *groupAscooscion;
   list<User *> mentionList;
   User *postOwner;
   int likeToDislikeRatio;
   string contents;

public:
   void addPersonToMention(User *person);
   void removePersonFromMentioned(User *person);
   User *givePostOwner(void);
   virtual void show();
   int giveLikeToDislikeRatio(void);
   bool checkWheterPersonIsOwner(User *person);
   std::string givePostContents(void);
   void modifyContents(std::string newContents, User *editor);
   void setGroupAssociation(UserGroup *group);
   Post(User *owner, string contents);
   Post(User *owner, UserGroup *whereItWasPosted, string contents);
   ~Post();
};

/***********************************************************************
 * Module:  Voteings.h
 * Author:  WhiteSweatShirt
 * Modified: niedziela, 4 stycznia 2026 14:59:35
 * Purpose: Declaration of the class Voteings
 ***********************************************************************/
class Voteings : public Post
{

protected:
private:
   int optionsOfVoting;
   int currenamountOfLead;
   bool oneUserOneVote;
   std::string endDate;
   int result;
   list<User *> usersWhoHadVoted;

public:
   bool checkWheterUserVoted(User *user);
   void voteByUser(User *user, bool forAvganist);
   void setEndDate(string date);
   int giveResult(void);
   void setRulesOfVoting(bool oneVotePerUser);
   virtual void show(void);
   Voteings(User *owner, string contents, bool oneVotePerUser);
};
#include "User.h"
#endif