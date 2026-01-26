/***********************************************************************
 * Module:  Archer.h
 * Author:  franc
 * Modified: poniedzia³ek, 26 stycznia 2026 19:55:22
 * Purpose: Declaration of the class Archer
 ***********************************************************************/

#if !defined(__UMLClassDiagram_1_Archer_h)
#define __UMLClassDiagram_1_Archer_h

#include <ActiveActor.h>

class Archer : public ActiveActor
{
public:
   void riposte(void);

protected:
private:

};

#endif