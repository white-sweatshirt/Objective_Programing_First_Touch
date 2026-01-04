/***********************************************************************
 * Module:  Event.h
 * Author:  WhiteSweatShirt
 * Modified: niedziela, 4 stycznia 2026 15:09:52
 * Purpose: Declaration of the class Event
 ***********************************************************************/

#ifndef __UMLClassDiagram_1_Event_h
#define __UMLClassDiagram_1_Event_h
#include "Post.h"
class Event : public Post
{
private:
   string location;
   vector<User *> participants;
   std::string date;

public:
   int sendNotyfication(void);
   int setLocation(string newLocation);
   int addParticipant(void);
   int sendReminder(void);
   
};

#endif