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
// to solve your problems with compilation add defintions to all destructors and constructros
// it is fault of compiler again... as well as all virtural methods all of them :(
//https://stackoverflow.com/questions/3065154/undefined-reference-to-vtable - co sie jebie
int main(void)
{
    srand(time(NULL));
    UserInterface *startingInterface=new UserInterface();
    Location * nowCreatedLocation=new Location("Starting Town");
    
    nowCreatedLocation->addNewSublocation(new SubLocation(new NPCTrader(),"Sklep Handlarza"));
    nowCreatedLocation->addNewSublocation(new SubLocation(new NPCCrafter(),"Smith"));
    nowCreatedLocation->addNewSublocation(new SubLocation(new NPCQuestGiver,"Wise Old Wizzard's Tower"));
    startingInterface->addLocation(nowCreatedLocation);
    
    nowCreatedLocation=new Location("Dark Fortress");
    nowCreatedLocation->addNewSublocation(new SubLocation(new Wizzard,"Corrupted Mage layar"));
    nowCreatedLocation->addNewSublocation(new SubLocation(new Warrior, "Petty thief hanza"));
    nowCreatedLocation->addNewSublocation(new SubLocation(new Archer,"Fallen RobinHood"));

    startingInterface->addLocation(nowCreatedLocation);
    
    nowCreatedLocation=nullptr;
    delete startingInterface;
    //fi.
    return 0;
}