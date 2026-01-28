/***********************************************************************
 * Module:  ActiveActor.cpp
 * Author:  franc
 * Modified: poniedzia�ek, 26 stycznia 2026 20:09:16
 * Purpose: Implementation of the class ActiveActor
 ******* ****************************************************************/
#include "NPC.h"
#include "ActiveActor.h"
ActiveActor::ActiveActor(int hP, int maxHp, int strenght, int inteligence, int agility)
    : hP(hP), maxHp(maxHp), strenght(strenght), inteligence(inteligence), agility(agility)
{
   level = 1;
   currentExp = 0;
   timeToSpecialAttack = 0;
   money = 0.0;
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

int ActiveActor::Attack(ActiveActor *actor)
{
   return strenght;
}

void ActiveActor::defendYourself(int attackPoints)
{
   if (attackPoints > 0)
      this->hP -= attackPoints - this->strenght;
}
void Archer::riposte(void)
{
   // TODO : implement
}

int Warrior::Attack(ActiveActor *actor)
{
   return strenght + agility;
}

int Archer::Attack(ActiveActor *actor)
{
   return inteligence + agility;
}

int Wizzard::Attack(ActiveActor *actor)
{
   return inteligence + agility;
}
