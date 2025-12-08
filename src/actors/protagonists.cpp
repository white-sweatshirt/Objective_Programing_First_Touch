#include "protagonists.h"

Protagonist::Protagonist(string name, string startingLocation, Map *map) : 
Actor(name, startingLocation, map)
{
}
void Protagonist::doTherapy(Protagonist *target)
{
    cout << this->giveName() << "staram sie pomoc: " << target->giveName() << endl;
}
Protagonist::~Protagonist()
{
}