/***********************************************************************
 * Module:  ActiveActor.h
 * Author:  franc
 * Modified: poniedzia�ek, 26 stycznia 2026 20:09:16
 * Purpose: Declaration of the class ActiveActor
 ***********************************************************************/

#ifndef ACTIVE_ACTOR_H
#define ACTIVE_ACTOR_H
class NPC;
class ActiveActor
{
protected:
   int maxHp;
   int hP;
   int level;
   int strenght;
   int inteligence;
   int agility;
   int currentExp;
   int timeToSpecialAttack;
public:
   int dieAndGiveExp(void);
   virtual int Attack(ActiveActor *actor);
   virtual void askForHealing(NPC *npc);
   void defendYourself(void);
   virtual int specialAttack();
   void resetSpecialAttack();
};

class Warrior : public ActiveActor
{
public:
   int Attack(ActiveActor *actor);

protected:
private:
};

class Archer : public ActiveActor
{
public:
   int Attack(ActiveActor *actor);

protected:
   void riposte();

private:
};
class Wizzard : public ActiveActor
{
public:
   int Attack(ActiveActor *actor);
};

#endif