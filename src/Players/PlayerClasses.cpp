#include "PlayerClasses.h"
bool PlayerWarrior::specialAttack(ActiveActor* target)
{
    return 2 * attack(target) + (weapon ? weapon->calculateBonus(strenght) : 0);
}

bool PlayerArcher::specialAttack(ActiveActor* target)
{
    return 2 * attack(target) + (weapon ? weapon->calculateBonus(agility) : 0);
}

bool PlayerWizzard::specialAttack(ActiveActor* target)
{
    return 2 * attack(target) + (weapon ? weapon->calculateBonus(inteligence) : 0);
}