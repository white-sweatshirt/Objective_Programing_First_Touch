#include "villans.h"

Bear::Bear(string name, string location, Map *map) : Actor(name, location, map)
{}
Bear::~Bear()
{
    for (auto w : family)
        family.pop_back();
}
void Bear::beHappyAboutReturnToHome()
{
    cout << "jestesmy w domu pojde zjesc owsianke i sie zdrzemnac" << endl;
}
void Bear::complainAboutPorridge(string heatLevel)
{
    cout << "owsianka byla " << heatLevel << endl;
}
void Bear::eatPorridge()
{
    this->eatenPorridge = true;
}
void Bear::goesToSleep()
{
    this->isConcious = false;
}

void Bear::tryToCatch(Actor *target)
{
    // w bajce nie ma nu pagadim
    cout << "nu pogadim " << target->giveName() << endl;
}
void Bear::addToFamily(Actor *meberToAdd)
{
    family.push_back(meberToAdd);
}
void humanVillan::takeGoonWithYou(string nameOfGoon)
{
    goons.push_back(new Actor(nameOfActor));
}
humanVillan::~humanVillan()
{
    for (auto a : goons)
        delete a;
}