/***********************************************************************
 * Module:  ActiveActor.cpp
 * Author:  franc
 * Modified: poniedzia�ek, 26 stycznia 2026 20:09:16
 * Purpose: Implementation of the class ActiveActor
 ***********************************************************************/

#include "ActiveActor.h"
#include "NPC.h"
int ActiveActor::dieAndGiveExp(void)
{
   return level * 10;
}

int ActiveActor::Attack(ActiveActor *actor)
{
   // abstarct place holder
}

void ActiveActor::defendYourself(void)
{
   // abstarct place holder
}
void Archer::riposte(void)
{
   // abstarct place holder
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

void ActiveActor::askForHealing(NPCHealer *healer)
{
   {
      healer->healPlayerForFee(this);
   }
}
bool ActiveActor::payForHealing(double amount)
{
   if (this->money > amount)
   {
      this->money -= amount;
      return true;
   }
   else
      return false;
}