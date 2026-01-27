/***********************************************************************
 * Module:  ActiveActor.h
 * Author:  franc
 * Modified: poniedzia�ek, 26 stycznia 2026 20:09:16
 * Purpose: Declaration of the class ActiveActor
 ***********************************************************************/

#ifndef ACTIVE_ACTOR_H
#define ACTIVE_ACTOR_H

class ActiveActor
{
private:
int hP;
int level

public:
   int dieAndGiveExp(void);
   void Attack(void);
   void defendYourself(void);



};

class Warrior : public ActiveActor
{
public:
protected:
private:

};

class Archer : public ActiveActor
{
public:
protected:
void riposte();
private:

};
class Wizzard:public ActiveActor
{

};

#endif