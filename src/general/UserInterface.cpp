#include "UserInterface.h"
#include "TemplateLib.h"
using namespace std;
void UserInterface::showGeneralPosibilites(void)
{
    cout << "0. Idz do lokacji"<<endl;
    cout << "1. Sprawdz ekwipunek"<<endl;
    cout << "2. Sprawdz statystyki postaci"<<endl;
    cout << "3. Interakcja z NPC"<<endl;
    cout << "4. Sprawdz questy"<<endl;
    cout << "5. Zapisz gre"<<endl;
    cout << "6. Wczytaj gre"<<endl;
    cout << "7. Zatakuj przeciwnika"<<endl;
    cout << "8. Wyjdz z gry"<<endl;
}
void UserInterface::showGoingMenu()
{
    
    
}
void UserInterface::showFightingOptions(void)
{

}
void UserInterface::showTradingOptions(void)
{
    
}
void UserInterface::showSubLocationOptions(void){

}
void UserInterface::askForUserInput(void (UserInterface::*menuOption)(void))
{
}
