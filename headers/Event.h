#ifndef __UMLClassDiagram_1_Event_h
#define __UMLClassDiagram_1_Event_h
#include "User.h"
class Event: public Post
{
private:
   string location;
   vector<User *> participants;
   std::string date;

public:
   void setLocation(string newLocation);
   void addParticipant(void);
   void sendReminder(void);
   
};

#endif