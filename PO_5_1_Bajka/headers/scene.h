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
    void getChanged(string newState);
    void changeToFinalScene();
    void createEndingScene();
    string giveLocation();
    vector<GhostOfPast *> *createCrystalCave();
};
#endif