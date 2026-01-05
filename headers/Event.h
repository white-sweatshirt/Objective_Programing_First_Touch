#ifndef __UMLClassDiagram_1_Event_h
#define __UMLClassDiagram_1_Event_h
class User;
class Post;

#include "Post.h"
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
   void show();
   
};

#endif