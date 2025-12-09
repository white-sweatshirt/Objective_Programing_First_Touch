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
    // not realy an idea.
    void changeLocation(string newLocation, Scene *scene);
};

#endif