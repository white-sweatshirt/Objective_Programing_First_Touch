/***********************************************************************
 * Module:  NPCQuestGiver.h
 * Author:  franc
 * Modified: poniedzia³ek, 26 stycznia 2026 19:26:18
 * Purpose: Declaration of the class NPCQuestGiver
 ***********************************************************************/

#if !defined(__UMLClassDiagram_1_NPCQuestGiver_h)
#define __UMLClassDiagram_1_NPCQuestGiver_h

class Quest;

#include <NPC.h>

class NPCQuestGiver : public NPC
{
public:
   void giveQuest(void);
   void realiseReward(void);

   Quest** quest;

protected:
private:

};

#endif