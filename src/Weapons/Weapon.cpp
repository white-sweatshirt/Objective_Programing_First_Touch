/***********************************************************************
 * Module:  Weapon.cpp
 * Author:  franc
 * Modified: poniedzia�ek, 26 stycznia 2026 19:58:16
 * Purpose: Implementation of the class Weapon
 ***********************************************************************/

#include "Weapon.h"
#include "Player.h"
void Items::equipItem(void)

{}
int RangedWeapon::calculateBonus(int agility)
{
    return damageBonus + (agility * agilityBonus);
}

int MeeleWeapon::calculateBonus(int strength)
{
    return damageBonus + (strength * strenghtBonus);
}

int MagicWeapon::calculateBonus(int intelligence)
{
    return damageBonus + static_cast<int>(intelligence * magicalMultiplier + additionalDamage);
}