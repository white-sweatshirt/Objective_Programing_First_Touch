#ifndef USER_INTERFACE
#define USER_INTERFACE
class ActiveActor;
class Player;
class NPC;
class Location;
class ImportantPlace;
class Quest;
// what if i would put all interaction with user in giant class named user interface
// that class would store information about :
// pointer to player, pointer to location in with player is in
// pointer to sub location of player and its posibilites.
// would store functions resposiable for choices that player would make
// also it would store with npc is in range to be interacted
// information wheter player is engaged in fight (if they can use world map)
// vector of possiable locations where player might go.
// choices in general menu would produce sub menus implemented in function pointers
// that would be specyfied menus (not sure about it->)for in those functions
class UserInterface
{
private:
    bool playerInFight;
    Player *pc; // pc - player character
    NPC *npc;
    ActiveActor *opponent;
    ImportantPlace *currentSublocation;
    Location *currentLocation;

protected:
    void showGeneralPosibilites(void);
    void showGoingMenu();
    void showInventoryMenu(void);
    void showFightingOptions(void);
    void showInteractionOptions(void);
    void showSubLocationOptions(void);
    void askLocationToShowInterestingPlaces();
    void simulatePlayerFight(void);
    void redetictFromMainMenu(int choice);

public:
    void askForUserInput();
    bool checkIfUserFights(void);
    ~UserInterface();
};
#endif