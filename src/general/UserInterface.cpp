#include "UserInterface.h"
#include "TemplateLib.h"
#include "Player.h"
#include "Location.h"
#include "NPC.h"
#include "PlayerClasses.h"
#include "SubLocation.h"

using namespace std;
// maybe add class that would be resposibale just for showing functions of certain kind
void UserInterface::addLocation(Location *loc)
{
    this->allLocations.push_back(loc);
}
/*general menu*/
void UserInterface::showGeneralPosibilites(void)
{
    cout << "0. Idz do lokacji" << endl;
    cout << "1. Interakcja z ekwipunek" << endl;
    cout << "2. Sprawdz statystyki postaci" << endl;
    cout << "3. Interakcja z NPC" << endl;
    cout << "4. Sprawdz questy" << endl;
    cout << "5. Zapisz gre (doesn't work)" << endl;
    cout << "6. Wczytaj gre (doesn't work)" << endl;
    cout << "7. Zatakuj przeciwnika" << endl;
    cout << "8. Zobacz mape aktualnej lokacji" << endl;
    cout << "9. Wyjdz z gry" << endl;
}
void UserInterface::askForUserInput(bool &maintainGame)
{
    int choice = -1;
    if (this->playerInFight)
    {
        simulatePlayerFight(maintainGame);
        return;
    }
    choice = templateLib::getStandardChoiceResult(this, showGeneralPosibilites, 0, 9);
    cout << "wprowadzono: " << choice << endl;
    redetictFromMainMenu(choice, maintainGame);
}
void UserInterface::redetictFromMainMenu(int choice, bool &maintainGame)
{
    int secundChoice = 0;
    switch (choice)
    {
    case 0:
        secundChoice = templateLib::getStandardChoiceResult(this, showGoingMenu, 0, 2);
        interprateChosenRoute(secundChoice);
        break;

    case 1:
        secundChoice = templateLib::getStandardChoiceResult(this, showInventoryMenu, 0, 2);
        InterprateChosenInventoryResult(secundChoice);
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
        this->currentLocation->showAllSublocations();
        break;
    case 9:
        maintainGame = false;
        break;
    default:
        break;
    }
}
/*fighting functions*/
void UserInterface::showFightingOptions(void)
{
    cout << "0. Zatakuj przeciwnika" << endl;
    cout << "1. Wykonaj atak specjalny" << endl;
    cout << "2. Uciekaj (moga pojawic sie obrazenia)" << endl;
    cout << "3. podejrzyj swoje statystki do walki" << endl;
    cout << "4. podejrzyj statystyki wroga do walki " << endl;
}
void UserInterface::simulatePlayerFight(bool &maintainGame)
{
    if (!opponent)
    {
        playerInFight = false;
        return;
    }
    cout << "obecne zdrowie gracza: " << this->pc->giveCurrentHp() << endl;
    cout << "obecne zdrowie wroga: " << this->opponent->giveCurrentHp() << endl;
    int choice = templateLib::getStandardChoiceResult(this, showFightingOptions, 0, 4);
    bool opponetWillGetRevange = true;
    switch (choice)
    {
    case 0:
        this->pc->attack(this->opponent);
        opponetWillGetRevange = true;
        break;
    case 1:

        this->pc->specialAttack(opponent);
        opponetWillGetRevange = true;
        break;
    case 2:
        playerInFight = false;
        opponetWillGetRevange = true;
        break;
    case 3:
        this->pc->giveVitalInfo();
        opponetWillGetRevange = false;
        break;
    case 4:
        this->opponent->giveVitalInfo();
        opponetWillGetRevange = false;
        break;
    default:
        opponetWillGetRevange = false;
        break;
    }

    if (this->opponent->giveCurrentHp() > 0 && opponetWillGetRevange)
        this->opponent->attack(pc);
    else if (this->pc->giveCurrentHp() <= 0)
    {
        cout << "Game over!" << endl;
        maintainGame = false;
    }
    else if (this->opponent->giveCurrentHp() <= 0)
    {
        this->pc->gainExperience(opponent->dieAndGiveExp());
        this->pc->getMonetaryReward(opponent->dieAndGiveMoney());
        delete opponent;

        this->pc->checkLevelUp();
        this->playerInFight = false;
    }
}
/*traveling functions*/
void UserInterface::showGoingMenu()
{
    cout << "0. idz do innej lokalizcji" << endl;
    cout << "1. idzi do innej sublokacji" << endl;
    cout << "2. Zostan gdzie jestes" << endl;
}
void UserInterface::showPossiableLocations(void)

{
    std::cout << "mozliwe lokacje do podrozy: " << std::endl;
    templateLib::showContentsOfContainerWithCounter(this->allLocations);
}
void UserInterface::showPossiableSubLocations()
{
    std::cout << "Mozliwe sublokacje do wyprawy: " << std::endl;
    if (this->currentLocation)
        currentLocation->showAllSublocations();
    else
        std::cout << "You are not in any location." << std::endl;
}
void UserInterface::choseSublocationToVenture(void)
{
    int choice = -1;
    choice = templateLib::getStandardChoiceResult(this,
                                                  showPossiableSubLocations,
                                                  0, this->currentLocation->giveNumberOfSublocations() - 1);
    this->currentSublocation = this->currentLocation->giveSublocationWithNumber(choice);
    this->npc = currentSublocation->giveNPC();
    this->opponent = currentSublocation->giveAntagonist();
}
void UserInterface::choseLocationToVenture(void)
{
    int choice = -1;
    choice = templateLib::getStandardChoiceResult(this,
                                                  showPossiableLocations,
                                                  0, this->allLocations.size() - 1);
    this->currentLocation = allLocations[choice];
    if (currentLocation)
    {
        this->currentSublocation = this->currentLocation->giveSublocationWithNumber(0);
        this->npc = this->currentSublocation->giveNPC();
        this->opponent = this->currentSublocation->giveAntagonist();
    }

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

/*inventory options*/
void UserInterface::showInventoryMenu(void)
{
    cout << "0. Zobacz ekwipunek" << endl;
    cout << "1. wyrzuc przedmiot" << endl;
    cout << "2. zamknij ekwipunek" << endl;
}
void UserInterface::InterprateChosenInventoryResult(int choice)
{
    switch (choice)
    {
    case 0:
        pc->showInventory();
        break;
    case 1:
        pc->throwAwayItem();
        break;
    case 2:
        break;
    default:
        break;
    }
}
#include <stdlib.h>
/*set Up of adventure potentialy new class*/
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