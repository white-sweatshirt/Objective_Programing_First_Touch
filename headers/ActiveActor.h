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
class Item;
class ActiveActor
{
   friend NPCHealer;

protected:
   std::string name;
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
   virtual int giveAttackPoints() = 0;

public:
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
   ActiveActor(int hP, int strenght, int inteligence, int agility);
   ActiveActor();
   ActiveActor(std::string name);
   ActiveActor(int hP, int strenght, int inteligence, int agility, std::string name);
   virtual ~ActiveActor() = default;
};

class Warrior : public virtual ActiveActor
{
protected:
   virtual int giveAttackPoints(void) override;

public:
   Warrior();
   virtual ~Warrior() = default;
};

class Archer : public virtual ActiveActor
{

protected:
   virtual int giveAttackPoints() override;

public:
   Archer();
   virtual ~Archer() = default;
};
class Wizzard : public virtual ActiveActor
{
protected:
   virtual int giveAttackPoints() override;

public:
   Wizzard();
   virtual ~Wizzard() = default;
};

#endif