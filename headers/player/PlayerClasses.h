#ifndef PLAYER_CLASSES_H
#define PLAYER_CLASSES_H
#include "Player.h"
#include "ActiveActor.h"

class PlayerArcher : public virtual Archer, public virtual Player
{
public:
    ~PlayerArcher() override = default;
    int calculateWeaponBonus();
    bool specialAttack(ActiveActor * actor) override; // New virtual module for special attack
};

class PlayerWizzard : public virtual Wizzard, public virtual Player
{
public:
    ~PlayerWizzard() override = default;
    int calculateWeaponBonus();
    bool specialAttack(ActiveActor * actor) override; // New virtual module for special attack
};

class PlayerWarrior : public virtual Warrior, public virtual Player
{
public:
    ~PlayerWarrior() override = default;
    int calculateWeaponBonus();
    bool specialAttack(ActiveActor * actor) override; // New virtual module for special attack
};

#endif