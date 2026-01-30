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

public:
   ActiveActor(int hP, int maxHp, int strenght, int inteligence, int agility);
   ActiveActor();
   virtual void giveVitalInfo(void);

   int dieAndGiveExp(void);
   virtual bool attack(ActiveActor *actor);
   int giveCurrentHp(void);
   void askForHealing(NPCHealer *npc);
   bool payForSth(double amount);

   virtual bool defendYourself(int attackPoints);
   virtual bool specialAttack(ActiveActor *target);
   void resetSpecialAttack();
   ~ActiveActor() = default;
};

class Warrior : public virtual ActiveActor
{
public:
   virtual bool attack(ActiveActor *actor) override;
   virtual bool specialAttack(ActiveActor *target) override;
      Warrior();

};

class Archer : public virtual ActiveActor
{
   
protected:
   void riposte();

public:

   virtual bool attack(ActiveActor *actor) override;
   virtual bool specialAttack(ActiveActor *target) override;
   Archer();

};
class Wizzard : public virtual ActiveActor
{
public:
   virtual bool attack(ActiveActor *actor) override;
   virtual bool specialAttack(ActiveActor *target) override;
      Wizzard();

};

#endif