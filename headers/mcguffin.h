#ifndef MCGUFFIN_H
#define MCGUFFIN_H
#include "actors.h"
#include "scene.h"
class Actor;
class Map
{
protected:
    Actor *owner;
public:
   void changeLocation(string newLocation,Scene*scene);
};

#endif