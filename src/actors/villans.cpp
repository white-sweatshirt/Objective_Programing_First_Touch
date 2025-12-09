#include "villans.h"

Bear::Bear(string name, string location, Map *map) : Actor(name, location, map)
{
    this->eatenPorridge = false;
    this->isConcious = true;
}
Bear::Bear(string name, string location) : Actor(name, location)
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
    cout << "oberwalem owsianka " << heatLevel << endl;
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
    cout << this->giveName() << "zaraz cie zlapienu pogadim " << target->giveName() << endl;
}

humanVillan::humanVillan(string name, string location) : Actor(name, location)
{
    this->prisonier = nullptr;
}
humanVillan::humanVillan(string name, string location, Map *map) : Actor(name, location, map)
{
    this->prisonier = nullptr;
}
void humanVillan::captureHero(Protagonist **hero)
{
    this->prisonier = *hero;
    *hero = nullptr;
}
Protagonist *humanVillan::loseControlOverHero()
{
    Protagonist *p = this->prisonier;
    this->prisonier = nullptr;
    return p;
}
void humanVillan::takeGoonWithYou(string nameOfGoon)
{
    goons.push_back(new Actor(nameOfActor));
}
void humanVillan::askForHelpWithThief(vector<Bear *> &bearsSurrogitiveFamilly, Actor *thief)
{
    cout << "-brac go " << thief->giveName() << endl;
    for (auto bear : bearsSurrogitiveFamilly)
        bear->attackActor(thief);
}
humanVillan::~humanVillan()
{
    for (auto a : goons)
        delete a;
}

void Death::scareHero(Protagonist *hero)
{
    cout << "buj sie mnie : "<<this->giveName();
    hero->getStressed();
}
void Death::destroyGhost(GhostOfPast *ghost)
{
    cout << "niszcze duszka dla wiekszego efektu\n";
}