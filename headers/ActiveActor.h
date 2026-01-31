/***********************************************************************
 * Module:  ActiveActor.h
 * Author:  franc
 * Modified: poniedzia�ek, 26 stycznia 2026 20:09:16
 * Purpose: Declaration of the class ActiveActor
 ***********************************************************************/

#ifndef ACTIVE_ACTOR_H
#define ACTIVE_ACTOR_H
class NPC;
class NPCHealer;
class ActiveActor
{
   friend NPCHealer;
protected:
   int maxHp;
   int hP;
   int level;
   int strenght;
   int inteligence;
   int agility;
   int currentExp;
   int timeToSpecialAttack;
   int timeCurrentlyWaitedToAttack;
   double money;

   Item *weapon;
   virtual int giveAttackPoints()=0;

public:
   ActiveActor(int hP, int maxHp, int strenght, int inteligence, int agility);
   ActiveActor();
   void giveVitalInfo(void);

   int dieAndGiveExp(void);
   bool attack(ActiveActor *actor);
   int giveCurrentHp(void);
   void askForHealing(NPCHealer *npc);
   bool payForSth(double amount);
   int giveInteligence(void);
   int giveAgility(void);
   int giveStrenght(void);
   int calculateWeaponBonus(void);
   bool defendYourself(int attackPoints);
   bool specialAttack(ActiveActor *target);
   virtual void resetSpecialAttack() = 0;
   ~ActiveActor() = default;
};

class Warrior : public virtual ActiveActor
{
protected:
   virtual int giveAttackPoints(void) override;

public:
   Warrior();
};

class Archer : public virtual ActiveActor
{

protected:
   virtual int giveAttackPoints() override;

public:
   Archer();
};
class Wizzard : public virtual ActiveActor
{
protected:
   virtual int giveAttackPoints() override;

public:
   Wizzard();
};

#endif