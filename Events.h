/***********************************************************************
 * Module:  Events.h
 * Author:  WhiteSweatShirt
 * Modified: niedziela, 4 stycznia 2026 15:09:52
 * Purpose: Declaration of the class Events
 ***********************************************************************/

#ifndef(__UMLClassDiagram_1_Events_h)
#define __UMLClassDiagram_1_Events_h

#include <Post.h>

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