/***********************************************************************
 * Module:  Post.h
 * Author:  WhiteSweatShirt
 * Modified: niedziela, 4 stycznia 2026 15:27:46
 * Purpose: Declaration of the class Post
 ***********************************************************************/

#ifndef __UMLClassDiagram_1_Post_h
#define __UMLClassDiagram_1_Post_h

#include <iostream>
#include <vector>
#include <list>

using namespace std;
class Post
{
private:
protected:
   int pepoleMentioned;
   std::string contetns;
   int picturesLink;
   int groupAscooscion;
   int likeToDislikeRatio;
   User *postOwner;

public:
   void addPersonToMention(void);
   void removePersonFromMentioned(void);
   User *givePostOwner(void);
   bool checkWheterPersonIsOwner(User *actor);

   void giveLikeToDislikeRatio(void);

   std::string givePostContents(void);
   void modyfiyContetns(void);
   bool addPictureLink(void);
   bool removePictureLink(void);

   void deletePost(void);
   Post(User *owner);
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
public:
   int checkWheterUserVoted(void);
   int voteByUser(void);
   int setEndDate(void);
   std::string giveResult(void);

protected:
private:
   int participants;
   int optionsOfVoting;
   int currenamountOfLead;
   bool oneUserOneVote;
   std::string endDate;
   std::string result;
};

#endif