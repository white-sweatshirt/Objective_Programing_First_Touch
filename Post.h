/***********************************************************************
 * Module:  Post.h
 * Author:  WhiteSweatShirt
 * Modified: niedziela, 4 stycznia 2026 15:27:46
 * Purpose: Declaration of the class Post
 ***********************************************************************/

#ifndef __UMLClassDiagram_1_Post_h
#define __UMLClassDiagram_1_Post_h
#include <iostream>
using namespace std;
class Post
{
   private:

   protected:
   int pepoleMentioned;
   std::string contetns;
   int picturesLink;
   int groupAscooscion;

public:
   void addPersonToMention(void);
   void removePersonFromMentioned(void);
   void deletePost(void);
   void* postOwner(void);
   bool checkWheterPersonIsOwner(User *actor);
   void modyfiyContetns(void);
   std::string readPost(void);


};
/***********************************************************************
 * Module:  Votings.h
 * Author:  WhiteSweatShirt
 * Modified: niedziela, 4 stycznia 2026 14:59:35
 * Purpose: Declaration of the class Votings
 ***********************************************************************/
class Votings : public Post
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

class Events : public Post
{
public:
   int sendNotyfication(void);
   int setLocation(void);
   int addParticipant(void);
   int sendReminder(void);

protected:
private:
   int location;
   int participants;
   std::string date;


};

#endif