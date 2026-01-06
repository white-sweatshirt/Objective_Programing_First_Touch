/***********************************************************************
 * Module:  Event.cpp
 * Author:  WhiteSweatShirt
 * Modified: niedziela, 4 stycznia 2026 15:09:52
 * Purpose: Implementation of the class Event
 ***********************************************************************/
#include "Event.h"

void Event::setLocation(string setNewLocation)
{
   // TODO : implement
}
void Event::show()
{
   cout<<"host of event: "<<this->postOwner->giveName()<<endl;
   cout<<"contents of event : "<<this->contents<<endl;
   cout<<"date of event: "<<this->date<<endl;
   cout<<"location of event: "<<this->location<<endl;
   cout<<"participants: "<<endl;
   showContentsOfContainer(this->participants); 
   cout<<"-----------------------"<<endl;
}


void Event::addParticipant(User *newParticipant)
{
   this->participants.push_back(newParticipant);
}
void Event::removePersonFromParticipants(User *participantToRemove)
{
   removeElemetOfVector(this->participants,participantToRemove);
}
void Event::sendReminder(void)
{
   // TODO : implement
}

Event::~Event()
{
   this->participants.clear();
}
Event::Event(User *owner, string contents):Post(owner,contents)
{

}
Event::Event(User *owner,string contents, string location):Post(owner,contents)
{
   this->location=location;
}