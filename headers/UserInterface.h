#ifndef USER_INTERFACE
#define USER_INTERFACE
class ActiveActor;
class Player;
class NPC;
class Location;
class SubLocation;
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
#include <deque>
class UserInterface
{
private:
    bool playerInFight;
    Player *pc; // pc - player character
    NPC *npc;
    ActiveActor *opponent;
    SubLocation *currentSublocation;
    Location *currentLocation;
    std::deque<Location *> allLocations;

protected:
    void showGeneralPosibilites(void);

    void showGoingMenu(void);
    void showPossiableLocationsDestinations(void);
    void showPossiableSubLocationsDestinations(void);

    void choseSublocationToVenture(void);
    void choseLocationToVenture(void);
    void showInventoryMenu(void);

    void showFightingOptions(void);

    void simulatePlayerFight(bool &maintainGame);
    void redetictFromMainMenu(int choice, bool &maintainGame);
    void showOptionsInCreatingProtagonist(void);
    void interprateChosenRoute(int choice);
    void InterprateChosenInventoryResult(int choice);

public:
    void createProtagonist(void);
    void askForUserInput(bool &maintainGame);
    void addLocation(Location *loc);
    void performInitalSetUp();
    ~UserInterface();
};
#endif