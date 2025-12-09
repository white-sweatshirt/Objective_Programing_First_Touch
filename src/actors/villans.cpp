#include "villans.h"

Bear::Bear(string name, string location, Map *map) : Actor(name, location, map)
{
    this->eatenPorridge = false;
    this->isConcious = true;
}
Bear::Bear(string name, string location) : Actor(location, name)
{
}
Bear::~Bear()
{
}
void Bear::beHappyAboutReturnToHome()
{
    cout << "jestesmy w domu pojde zjesc owsianke i sie zdrzemnac" << endl;
}
void Bear::complainAboutPorridge(string heatLevel)
{
    cout << "oberwalem owsianka bedaca" << heatLevel << endl;
}
void Bear::eatPorridge()
{
    this->eatenPorridge = true;
}
void Bear::goesToSleep()
{
    this->isConcious = false;
}
void Bear::wakeUp()
{
    this->isConcious = false;
}
void Bear::tryToCatch(Actor *target)
{
    // w bajce nie ma nu pagadim
    cout << "nu pogadim " << target->giveName() << endl;
}

humanVillan::humanVillan(string name, string location) : Actor(name, location)
{
}
humanVillan::humanVillan(string name, string location, Map *map) : Actor(name, location, map)
{
}
void humanVillan::takeGoonWithYou(string nameOfGoon)
{
    goons.push_back(new Actor(nameOfActor));
}
void humanVillan::askForHelpWithThief(vector<Bear *> &bearsSurrogitiveFamilly, Actor *thief)
{
    cout << "brac go " << thief->giveName() << endl;
    for (auto bear : bearsSurrogitiveFamilly)
        bear->attackActor(thief);
}
humanVillan::~humanVillan()
{
    for (auto a : goons)
        delete a;
}