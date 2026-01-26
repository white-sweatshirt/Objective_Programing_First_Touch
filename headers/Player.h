/***********************************************************************
 * Module:  Player.h
 * Author:  franc
 * Modified: poniedzia³ek, 26 stycznia 2026 19:51:31
 * Purpose: Declaration of the class Player
 ***********************************************************************/

#if !defined(__UMLClassDiagram_1_Player_h)
#define __UMLClassDiagram_1_Player_h

class NPC;
class Items;
class Weapon;
class Quest;

class Player
{
public:
   void gotToNewPlace(void);
   void goToNewEnymy(void);
   void getExpirence(void);
   void askForQuest(void);
   void startDialogWithNPC(void);
   void consultMap(void);

   NPC** nPC;
   Items** items;
   Weapon** weapon;
   Quest** quest;

protected:
private:
   Item* body;
   Item* Hands;


};

#endif