/***********************************************************************
 * Module:  NPCHealer.h
 * Author:  franc
 * Modified: poniedzia³ek, 26 stycznia 2026 19:25:23
 * Purpose: Declaration of the class NPCHealer
 ***********************************************************************/

#if !defined(__UMLClassDiagram_1_NPCHealer_h)
#define __UMLClassDiagram_1_NPCHealer_h

#include <NPC.h>

class NPCHealer : public NPC
{
public:
   void healPlayerForFee(void);

protected:
private:

};

#endif