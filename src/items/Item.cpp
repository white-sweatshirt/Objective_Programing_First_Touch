/***********************************************************************
 * Module:  Weapon.cpp
 * Author:  franc
 * Modified: poniedzia�ek, 26 stycznia 2026 19:58:16
 * Purpose: Implementation of the class Weapon
 ***********************************************************************/

#include "Item.h"
#include "Player.h"
Item::Item(double value):
value(value)
{}
double Item::giveValue(void)
{
    return this->value;
}
int Item::calculateBonus(ActiveActor *wearer)
{
    return 0;
}
void Item::show()
{
    std::cout << "posiadasz przedmiot o wartosc: " << value << std::endl;
}
Weapon::Weapon(std::string name, int damgeBonus)
    :Item(damgeBonus*3), name(name), damageBonus(damgeBonus)
{
}
void Weapon::show()
{
    std::cout << "Weapon: " << name << ", Damage Bonus: " << damageBonus << std::endl;
}
void Weapon::setName(std::string name)
{
    this->name=name;
}
int RangedWeapon::calculateBonus(ActiveActor *const actor)
{
    return damageBonus + (actor->giveAgility() * agilityBonus);
}

int MeeleWeapon::calculateBonus(ActiveActor *const actor)
{
    return damageBonus + (actor->giveStrenght()* strenghtBonus);
}

int MagicWeapon::calculateBonus(ActiveActor *const actor)
{
    return damageBonus + static_cast<int>(actor->giveInteligence() * magicalMultiplier + additionalDamage);
}



RangedWeapon::RangedWeapon(std::string name, int damegeBonus)
    : Weapon(name, damegeBonus), agilityBonus(2)
{
}

MeeleWeapon::MeeleWeapon(std::string name, int damegeBonus)
    : Weapon(name, damegeBonus), strenghtBonus(2)
{
}

MagicWeapon::MagicWeapon(std::string name, int damegeBonus)
    : Weapon(name, damegeBonus), magicalMultiplier(2), additionalDamage(5.0)
{
}
