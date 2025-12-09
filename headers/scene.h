#ifndef SCENE_H
#define SCENE_H

#include "protagonists.h"
class GhostOfPast;
#include <iostream>
using namespace std;

class Scene
{
    string currentState;

public:
    void createHome();
    void introducecesBearsToHome();
    string giveLocation();
    void getChanged(string newState);
    vector<GhostOfPast *> *createCrystalCave();
};
#endif