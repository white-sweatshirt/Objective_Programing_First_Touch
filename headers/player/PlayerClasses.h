#ifndef PLAYER_CLASSES_H
#define PLAYER_CLASSES_H
#include "Player.h"
#include "ActiveActor.h"

class PlayerArcher : public Archer, public Player
{
public:
    ~PlayerArcher() override = default;
    int calculateWeaponBonus();
    int specialAttack(ActiveActor * actor) override; // New virtual module for special attack
};

class PlayerWizzard : public Wizzard, public Player
{
public:
    ~PlayerWizzard() override = default;
    int calculateWeaponBonus();
    int specialAttack(ActiveActor * actor) override; // New virtual module for special attack
};

class PlayerWarrior : public Warrior, public Player
{
public:
    ~PlayerWarrior() override = default;
    int calculateWeaponBonus();
    int specialAttack(ActiveActor * actor) override; // New virtual module for special attack
};

#endif