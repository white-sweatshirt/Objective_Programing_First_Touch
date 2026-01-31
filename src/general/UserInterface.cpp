#include "UserInterface.h"
#include "TemplateLib.h"
#include "Player.h"
#include "Location.h"
#include "NPC.h"
using namespace std;
void UserInterface::addLocation(Location *loc)
{
    this->allLocations.push_back(loc);

}
void UserInterface::showGoingMenu()
{
    cout << "0. idz do innej lokalizcji" << endl;
    cout << "1. idzi do innej sublokacji" << endl;
    cout << "2. Zostan gdzie jestes" << endl;
}
void UserInterface::showFightingOptions(void)
{
    cout << "0. Zatakuj przeciwnika" << endl;
    cout << "1. Wykonaj atak specjalny" << endl;
    cout << "2. Uciekaj (moga pojawic sie obrazenia)" << endl;
}
void UserInterface::showInteractionOptions(void)
{
    // if pointer to function wont work
    cout << "0. kup bron/przedmiot" << endl;
    cout << "1. sprzedaj bron/przedmiot " << endl;
    cout << " 2. Zamow bron" << endl;
    cout << "3. Zazadaj Nowego Questa" << endl;
    cout << "4. zakoncz rozmowe" << endl;
}
void UserInterface::showSubLocationOptions(void)
{
    if (!this->currentSublocation)
    {
        cerr << "brak sub lokacji!" << endl;
        return;
    }
}
void UserInterface::askLocationToShowInterestingPlaces()
{
    if (this->currentLocation)
        currentLocation->tellAboutInterestingLocations();
    else
        std::cout << "You are not in any location." << std::endl;
}
void UserInterface::showInventoryMenu(void)
{
    cout << "0. Zobacz ekwipunek" << endl;
    cout << "1. wyrzuc przedmiot" << endl;
    cout << "2. zamknij ekwipunek" << endl;
}
void UserInterface::showGeneralPosibilites(void)
{
    cout << "0. Idz do lokacji" << endl;
    cout << "1. Interakcja z ekwipunek" << endl;
    cout << "2. Sprawdz statystyki postaci" << endl;
    cout << "3. Interakcja z NPC" << endl;
    cout << "4. Sprawdz questy" << endl;
    cout << "5. Zapisz gre" << endl;
    cout << "6. Wczytaj gre" << endl;
    cout << "7. Zatakuj przeciwnika" << endl;
    cout << "8. Wyjdz z gry" << endl;
}
void UserInterface::redetictFromMainMenu(int choice)
{
    int secundChoice = 0;
    switch (choice)
    {
    case 0:
        secundChoice = templateLib::getStandardChoiceResult(this, showGoingMenu, 0, 2);
        break;
    case 1:
        secundChoice = templateLib::getStandardChoiceResult(this, showInventoryMenu, 0, 2);
        break;
    case 2:

        pc->giveVitalInfo();
    case 3:
        this->npc->getUserToChoseOption(pc);

        break;

    case 4:
        pc->showAllQuests();
        break;
    case 5:
        // nothing for now
        break;
    case 6:
        // nothing for now
        break;
    case 7:
        playerInFight = 1;
        break;
    case 8:
        // deconstructor here.
        exit(1);
    default:
        break;
    }
}
void UserInterface::simulatePlayerFight(void)
{
    int choice = templateLib::getStandardChoiceResult(this, showFightingOptions, 0, 2);
    if (choice == 0)
        this->pc->attack(this->opponent);

    else if (choice == 1)
        this->pc->specialAttack(opponent);
    else
        this->playerInFight = false;
    if (this->opponent->giveCurrentHp() > 0)
        this->opponent->attack(pc);
    else if (this->pc->giveCurrentHp() <= 0)
    {
        cout << "Game over!" << endl;
        // to be filled with destructor
        exit(1);
    }
    else if (this->opponent->giveCurrentHp() <= 0)
    {
        this->pc->gainExperience(opponent->dieAndGiveExp());
        delete opponent;

        this->pc->checkLevelUp();
        this->playerInFight = false;
    }
}
#include <stdlib.h>
void UserInterface::askForUserInput()
{
    int choice = -1;
    if (this->playerInFight)
    {
        simulatePlayerFight();
        return;
    }
    choice = templateLib::getStandardChoiceResult(this, showGeneralPosibilites, 0, 8);
}
UserInterface::~UserInterface()
{
    
    opponent = nullptr;
    currentSublocation = nullptr;
    templateLib::killVectorOfPointers(allLocations);
    delete pc;
    pc = nullptr;
}