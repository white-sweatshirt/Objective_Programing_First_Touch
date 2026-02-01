/***********************************************************************
 * Module:  ActiveActor.cpp
 * Author:  franc
 * Modified: poniedzia�ek, 26 stycznia 2026 20:09:16
 * Purpose: Implementation of the class ActiveActor
 ******* ****************************************************************/
#include "NPC.h"
#include "ActiveActor.h"
#include "TemplateLib.h"
#include "Item.h"
ActiveActor::ActiveActor(int hP, int strenght, int inteligence, int agility)
    : hP(hP), strenght(strenght), inteligence(inteligence), agility(agility)
{
   level = 1;
   currentExp = 0;
   timeCurrentlyWaitedToAttack = 0;
   timeToSpecialAttack = 100;
   money = 200.0;
   weapon = nullptr;
   this->name = "Generic name";
}

ActiveActor::ActiveActor(int hP, int strenght, int inteligence,
                         int agility, std::string name)
    : hP(hP), strenght(strenght), inteligence(inteligence), agility(agility),
      name(name)
{
   if(hP>0)
   this->maxHp=hP;
   else
   maxHp=hP=100;
   level = 1;
   currentExp = 0;
   timeCurrentlyWaitedToAttack = 0;
   timeToSpecialAttack = 100;
   money = 200.0;
   weapon = nullptr;
}
ActiveActor::ActiveActor(std::string name)
{
   this->hP = 100;
   this->maxHp=hP;
   this->level = 2;
   this->inteligence = 3;
   this->strenght = 3;
   this->agility = 3;
   this->money = 200;
   this->name = "Generic name 1";
   this->weapon=nullptr;
}
ActiveActor::ActiveActor()
{
   this->maxHp=100;
   this->hP = 100;
   this->level = 2;
   this->inteligence = 3;
   this->strenght = 3;
   this->agility = 3;
   this->money = 300;
   this->weapon=nullptr;
}
void ActiveActor::giveVitalInfo(void)
{
   std::cout << "obecny poziom: " << this->level << std::endl;
   std::cout << "obecne hp: " << this->hP << std::endl;
   std::cout << "max hp: " << this->maxHp << std::endl;
   std::cout << "sila :" << this->strenght << std::endl;
   std::cout << "inteligencja : " << this->inteligence << std::endl;
   std::cout << "zrecznosc: " << this->agility << std::endl;
   std::cout << "ilosc zlota: " << this->money << std::endl;
}
void ActiveActor::askForHealing(NPCHealer *healer)
{
   healer->healPlayerForFee(this);
}
bool ActiveActor::payForSth(double amount)
{
   if (amount <= money && amount > 0)
   {
      money -= amount;
      return true;
   }
   else
      return false;
}
int ActiveActor::dieAndGiveExp(void)
{
   return level * 10;
}
double ActiveActor::dieAndGiveMoney(void)
{
   return this->money;
}
bool ActiveActor::defendYourself(int attackPoints)
{
   if (attackPoints > 0)
      this->hP -= attackPoints - this->strenght;
   if (this->hP <= 0)
      return 0;
   return true;
}

int ActiveActor::calculateWeaponBonus(void)
{
   return weapon->calculateBonus(this);
}
int ActiveActor::giveCurrentHp(void)
{
   return this->hP;
}
bool ActiveActor::attack(ActiveActor *actor)
{
   return actor->defendYourself(inteligence + agility) ? 0 : 1;
}
bool ActiveActor::specialAttack(ActiveActor *target)
{
   if (timeToSpecialAttack <= 0)
   {
      constexpr int specialMuliplayer = 2;
      return target->defendYourself(specialMuliplayer * giveAttackPoints()) ? 0 : 1;
   }
   return false;
}

int Archer::giveAttackPoints(void)
{
   return (weapon ? strenght + agility + weapon->calculateBonus(this) : strenght + agility);
}
int ActiveActor::giveInteligence(void)
{
   return this->inteligence;
}

int ActiveActor::giveAgility(void)
{
   return this->agility;
}

int ActiveActor::giveStrenght(void)
{
   return this->strenght;
}
Archer::Archer() : ActiveActor()
{
}
int Warrior::giveAttackPoints(void)
{
   return (weapon ? strenght + agility + weapon->calculateBonus(this) : strenght + agility);
}
Warrior::Warrior() : ActiveActor()
{
}
int Wizzard::giveAttackPoints()
{
   return (weapon ? inteligence + agility + weapon->calculateBonus(this) : inteligence + agility);
}
Wizzard::Wizzard() : ActiveActor()
{
}
