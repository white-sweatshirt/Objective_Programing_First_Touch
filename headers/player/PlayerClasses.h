#ifndef PLAYER_CLASSES_H
#define PLAYER_CLASSES_H
#include "Player.h"
#include "ActiveActor.h"

class PlayerArcher : public virtual Archer, public virtual Player
{
public:
    ~PlayerArcher()  = default;
    
};

class PlayerWizzard : public virtual Wizzard, public virtual Player
{
public:
    ~PlayerWizzard()  = default;
};

class PlayerWarrior : public virtual Warrior, public virtual Player
{
public:
    ~PlayerWarrior()  = default;
};

#endif