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
class User;
class UserGroup;
class Post;

#include "Activity.h"
#include "User.h"
#include "UserGroup.h"

class Post: public Activity
{
protected:
   
   UserGroup *groupAscooscion;
   list<User *> mentionList;

public:
   void addPersonToMention(User *person);
   void removePersonFromMentioned(User *person);
   User *givePostOwner(void);

   int giveLikeToDislikeRatio(void);

   std::string givePostContents(void);
   void modifyContents(std::string newContents, User *editor);
   Post(User *owner, string contents);
   ~Post();
};

/***********************************************************************
 * Module:  Voteings.h
 * Author:  WhiteSweatShirt
 * Modified: niedziela, 4 stycznia 2026 14:59:35
 * Purpose: Declaration of the class Voteings
 ***********************************************************************/
class Voteings : public Activity
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
};

#endif