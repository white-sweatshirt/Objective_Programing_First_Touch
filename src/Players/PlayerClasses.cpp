#include "PlayerClasses.h"
int PlayerWarrior::specialAttack(ActiveActor* target)
{
    return 2 * Attack(target) + (weapon ? weapon->calculateBonus(strenght) : 0);
}

int PlayerArcher::specialAttack(ActiveActor* target)
{
    return 2 * Attack(target) + (weapon ? weapon->calculateBonus(agility) : 0);
}

int PlayerWizzard::specialAttack(ActiveActor* target)
{
    return 2 * Attack(target) + (weapon ? weapon->calculateBonus(inteligence) : 0);
}