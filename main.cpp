#include <iostream>
#include <time.h>

#include "NPC.h"
#include "NPCTrader.h"

#include "ActiveActor.h"
#include "Item.h"
#include "Location.h"
#include "Quest.h"

#include "SubLocation.h"
#include "TemplateLib.h"

#include "Player.h"
#include "UserInterface.h"
// to use plugs use <windows.h>
using namespace std;
string produceNameForVillan(void)
{
    const string names[] = {"Sauron", "Vader", "Goon", "Pimpek", "Ivan", "Ceseri", "Rambo",
                            "Nero", "Caligula", "Palpatine", "WhiteWalker", "Emyhr",
                            "Vladimir Harkonnen", "Gargamel", "Fred-Rautha"};
    const string adjectives[] = {"Terrible", "Dark", "Wicked",
                                 "Foulmounth", "Cruel", "Scary", "Terror of World"};
    return adjectives[rand() % (sizeof(adjectives) / sizeof(adjectives[0]))] +
           " " + names[rand() % (sizeof(names) / sizeof(names[0]))];
}
void setUpGame(UserInterface *startingInterface)
{
    Location *nowCreatedLocation = new Location("Starting Town");

    nowCreatedLocation->addNewSublocation(new SubLocation(new NPCTrader(), "Sklep Handlarza"));
    nowCreatedLocation->addNewSublocation(new SubLocation(new NPCCrafter(), "Smith"));
    nowCreatedLocation->addNewSublocation(new SubLocation(new NPCQuestGiver, "Wise Old Wizzard's Tower"));
    startingInterface->addLocation(nowCreatedLocation);

    nowCreatedLocation = new Location("Dark Fortress");
    nowCreatedLocation->addNewSublocation(new SubLocation(new Wizzard, "Corrupted Mage layar"));
    nowCreatedLocation->addNewSublocation(new SubLocation(new Warrior, "Petty thief hanza"));
    nowCreatedLocation->addNewSublocation(new SubLocation(new Archer, "Fallen RobinHood Hideout"));

    startingInterface->addLocation(nowCreatedLocation);
    nowCreatedLocation = new Location("Murky Village");
    nowCreatedLocation->addNewSublocation(new SubLocation(new Warrior, "Arena"));
    nowCreatedLocation->addNewSublocation(new SubLocation(new Archer, "Arena2"));
    nowCreatedLocation->addNewSublocation(new SubLocation(new NPCHealer, "healers Dent"));
    nowCreatedLocation->addNewSublocation(new SubLocation(new Wizzard(), "Dark Wizzard Tower"));
    startingInterface->addLocation(nowCreatedLocation);
    startingInterface->createProtagonist();
    startingInterface->performInitalSetUp();
    nowCreatedLocation = nullptr;
}
int main(void)
{
    fflush(stdout);
    srand(time(NULL));
    UserInterface *startingInterface = new UserInterface();
    setUpGame(startingInterface);
    bool maitainGame = true;
    while (maitainGame)
        startingInterface->askForUserInput(maitainGame);
    delete startingInterface;
    // fi.
    return 0;
}