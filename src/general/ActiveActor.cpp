/***********************************************************************
 * Module:  ActiveActor.cpp
 * Author:  franc
 * Modified: poniedzia�ek, 26 stycznia 2026 20:09:16
 * Purpose: Implementation of the class ActiveActor
 ******* ****************************************************************/
#include "NPC.h"
#include "ActiveActor.h"
#include "TemplateLib.h"

ActiveActor::ActiveActor(int hP, int maxHp, int strenght, int inteligence, int agility)
    : hP(hP), maxHp(maxHp), strenght(strenght), inteligence(inteligence), agility(agility)
{
   level = 1;
   currentExp = 0;
   timeCurrentlyWaitedToAttack = 0;
   timeToSpecialAttack=100;
   money = 200.0;
}
ActiveActor::ActiveActor()
{
   this->hP=100;
   this->level=2;
   this->inteligence=3;
   this->strenght=3;
   this->agility=5;
   this->money =100;
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

bool ActiveActor::attack(ActiveActor *actor)
{
   return actor->defendYourself(strenght) ? 0 : 1;
}

bool ActiveActor::defendYourself(int attackPoints)
{
   if (attackPoints > 0)
      this->hP -= attackPoints - this->strenght;
   if (this->hP <= 0)
      return 0;
   return true;
}
int ActiveActor::giveCurrentHp(void)
{
   return this->hP;
}
void Archer::riposte(void)
{}
Warrior::Warrior(): ActiveActor()
{

}

bool Warrior::attack(ActiveActor *actor)
{
   return actor->defendYourself(strenght + agility) ? 0 : 1;
}
Archer::Archer():ActiveActor()
{

}

bool Archer::attack(ActiveActor *actor)
{
   return actor->defendYourself(strenght + inteligence) ? 0 : 1;
}
Wizzard::Wizzard():ActiveActor()
{

}
bool Wizzard::attack(ActiveActor *actor)
{
   return actor->defendYourself(inteligence + agility) ? 0 : 1;
}
