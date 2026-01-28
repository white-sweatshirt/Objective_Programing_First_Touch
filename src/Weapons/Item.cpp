/***********************************************************************
 * Module:  Weapon.cpp
 * Author:  franc
 * Modified: poniedzia�ek, 26 stycznia 2026 19:58:16
 * Purpose: Implementation of the class Weapon
 ***********************************************************************/

#include "Item.h"
#include "Player.h"
void Item::equipItem(void)
{
}
double Item::giveValue(void)
{
    return this->value;
}
void Weapon::show()
{
    std::cout << "Weapon: " << name << ", Damage Bonus: " << damageBonus << std::endl;
}
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

Weapon::Weapon(std::string name, int damgeBonus)
    : name(name), damageBonus(damgeBonus)
{}

RangedWeapon::RangedWeapon(std::string name, int damegeBonus)
    : Weapon(name, damegeBonus), agilityBonus(2)
{}

MeeleWeapon::MeeleWeapon(std::string name, int damegeBonus)
    : Weapon(name, damegeBonus), strenghtBonus(3)
{}

MagicWeapon::MagicWeapon(std::string name, int damegeBonus)
    : Weapon(name, damegeBonus), magicalMultiplier(2), additionalDamage(5.0)
{}
