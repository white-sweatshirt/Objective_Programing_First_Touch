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

void ActiveActor::Attack(ActiveActor *actor)
{
   actor->defendYourself(strenght);
}

void ActiveActor::defendYourself(int attackPoints)
{
   if (attackPoints > 0)
      this->hP -= attackPoints - this->strenght;
}
void Archer::riposte(void)
{
   
}

void Warrior::Attack(ActiveActor *actor)
{
   actor->defendYourself(strenght + agility);
}

void Archer::Attack(ActiveActor *actor)
{
   actor->defendYourself(strenght + inteligence);
}

void Wizzard::Attack(ActiveActor *actor)
{
   actor->defendYourself(inteligence + agility);
}
