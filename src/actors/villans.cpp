#include "villans.h"
Bear::Bear(string name, string location, Map *map) : Actor(name, location, map)
{}

void Bear::beHappyAboutReturnToHome()
{
    cout << "jestesmy w domu pojde zjesc owsianke i sie zdrzemnac" << endl;
}
void Bear::complainAboutPorridge(string heatLevel)
{
    cout << "owsianka byla " << heatLevel << endl;
}
void humanVillan::takeGoonWithYou(string nameOfGoon)
{
    goons.push_back(new Actor(nameOfActor));
}
humanVillan::~humanVillan()
{
    for(auto a: goons)
        delete a;
}