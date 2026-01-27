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
   double money;

public:
   int dieAndGiveExp(void);
   virtual int Attack(ActiveActor *actor);
   virtual void askForHealing(NPCHealer *npc);
   virtual bool payForHealing(double amount);
   void defendYourself(void);
   virtual int specialAttack(ActiveActor *target);
   void resetSpecialAttack();
};

class Warrior : public ActiveActor
{
public:
   int Attack(ActiveActor *actor);
   int specialAttack(ActiveActor *target) override;

protected:
private:
};

class Archer : public ActiveActor
{
public:
   int Attack(ActiveActor *actor);
   int specialAttack(ActiveActor *target) override;

protected:
   void riposte();

private:
};
class Wizzard : public ActiveActor
{
public:
   int Attack(ActiveActor *actor);
   int specialAttack(ActiveActor *target) override;
};

#endif