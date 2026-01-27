/***********************************************************************
 * Module:  ActiveActor.cpp
 * Author:  franc
 * Modified: poniedzia�ek, 26 stycznia 2026 20:09:16
 * Purpose: Implementation of the class ActiveActor
 ***********************************************************************/

#include "ActiveActor.h"

////////////////////////////////////////////////////////////////////////
// Name:       ActiveActor::dieAndGiveExp()
// Purpose:    Implementation of ActiveActor::dieAndGiveExp()
// Return:     int
////////////////////////////////////////////////////////////////////////

int ActiveActor::dieAndGiveExp(void)
{
   return level *10;
}

////////////////////////////////////////////////////////////////////////
// Name:       ActiveActor::Attack()
// Purpose:    Implementation of ActiveActor::Attack()
// Return:     void
////////////////////////////////////////////////////////////////////////

int ActiveActor::Attack(ActiveActor * actor)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       ActiveActor::defendYourself()
// Purpose:    Implementation of ActiveActor::defendYourself()
// Return:     void
////////////////////////////////////////////////////////////////////////

void ActiveActor::defendYourself(void)
{
   // TODO : implement
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