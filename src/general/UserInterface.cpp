#include "UserInterface.h"
#include "TemplateLib.h"
#include "Player.h"
#include "Location.h"
#include "NPC.h"
#include "PlayerClasses.h"
#include "SubLocation.h"
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
void UserInterface::showPossiableLocationsDestinations(void)
{
    templateLib::showContentsOfContainerWithCounter(this->allLocations);
}

void UserInterface::showPossiableSubLocationsDestinations()
{
    if (this->currentLocation)
        currentLocation->showAllSublocations();
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
void UserInterface::choseSublocationToVenture(void)
{
    int choice = -1;
    choice = templateLib::getStandardChoiceResult(this,
                                                  showPossiableLocationsDestinations,
                                                  0, this->currentLocation->giveNumberOfSublocations() - 1);
    this->currentSublocation = this->currentLocation->giveSublocationWithNumber(choice);
}
void UserInterface::choseLocationToVenture(void)
{
    int choice = -1;
    choice = templateLib::getStandardChoiceResult(this,
                                                  showPossiableSubLocationsDestinations,
                                                  0, this->allLocations.size() - 1);
    this->currentLocation = allLocations[choice];
    if (currentLocation)
        this->currentSublocation = this->currentLocation->giveSublocationWithNumber(0);
    if (!currentLocation || !currentSublocation)
    {
        cerr << "brak sublokacji!!!!!" << endl;
        exit(2);
    }
}
void UserInterface::interprateChosenRoute(int choice)
{
    switch (choice)
    {
    case 0:
        choseLocationToVenture();
        break;
    case 1:
        choseSublocationToVenture();
        break;
    default:
        break;
    }
}

void UserInterface::redetictFromMainMenu(int choice, bool &maintainGame)
{
    int secundChoice = 0;
    switch (choice)
    {
    case 0:
        secundChoice = templateLib::getStandardChoiceResult(this, showGoingMenu, 0, 2);
        interprateChosenRoute(choice);
        break;

    case 1:
        secundChoice = templateLib::getStandardChoiceResult(this, showInventoryMenu, 0, 2);
        break;

    case 2:
        pc->giveVitalInfo();
        break;
        
    case 3:
        if (npc)
            this->npc->getUserToChoseOption(pc);
        else
            cout << "Brak npc do interakcji!" << endl;
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
        maintainGame = false;
    default:
        break;
    }
}
void UserInterface::simulatePlayerFight(bool &maintainGame)
{
    int choice = templateLib::getStandardChoiceResult(this, showFightingOptions, 0, 2);
    if (choice == 0)
        this->pc->attack(this->opponent);

    else if (choice == 1)
        if (opponent)
            this->pc->specialAttack(opponent);
        else
        {
            cout << "nie ma opponenta w tej lokacji";
            playerInFight = false;
            return;
        }
    else
        this->playerInFight = false;
    if (this->opponent->giveCurrentHp() > 0)
        this->opponent->attack(pc);
    else if (this->pc->giveCurrentHp() <= 0)
    {
        cout << "Game over!" << endl;
        maintainGame = false;
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
void UserInterface::askForUserInput(bool &maintainGame)
{
    int choice = -1;
    if (this->playerInFight)
    {
        simulatePlayerFight(maintainGame);
        return;
    }
    choice = templateLib::getStandardChoiceResult(this, showGeneralPosibilites, 0, 8);
    cout << "wprowadzono: " << choice << endl;
    redetictFromMainMenu(choice, maintainGame);
}
void UserInterface::showOptionsInCreatingProtagonist(void)
{
    cout << "0. Utworz Bochatera walczacego w zwarciu" << endl;
    cout << "1. Utworz bochatera lucznika" << endl;
    cout << "2. utworz bochatera czarodzieja" << endl;
}
void UserInterface::createProtagonist()
{
    int choice = -1;
    choice = templateLib::getStandardChoiceResult(this, showOptionsInCreatingProtagonist, 0, 2);
    cout << "Podaj imie bochatera: ";
    string name;
    cin >> name;
    switch (choice)
    {
    case 0:
        this->pc = new PlayerWarrior(name);
        break;
    case 1:
        this->pc = new PlayerArcher(name);
        break;
    case 2:
        this->pc = new PlayerWizzard(name);
        break;
    default:
        break;
    }
}
void UserInterface::performInitalSetUp(void)
{
    SubLocation *buckupSub = currentSublocation;
    Location *locBuckup = currentLocation;
    this->currentLocation = allLocations.front();
    this->currentSublocation = allLocations.front()->giveSublocationWithNumber(0);
    if (!currentSublocation)
    {
        this->currentLocation = locBuckup;
        this->currentSublocation = currentSublocation;
        cerr << "nie prawidlowa sublokacja powrot do poprzedniej lokacji!" << endl;
    }
    this->npc = currentSublocation->giveNPC();
    this->opponent = currentSublocation->giveAntagonist();
}
UserInterface::~UserInterface()
{

    opponent = nullptr;
    currentSublocation = nullptr;
    templateLib::killVectorOfPointers(allLocations);
    delete pc;
    pc = nullptr;
}