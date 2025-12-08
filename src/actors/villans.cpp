#include "villans.h"
Bear::Bear(string name,string location,Map* map):
Actor(name,location,map)
{

}
void Bear::beHappyAboutReturnToHome()
{
    cout << "jestesmy w domu pojde zjesc owsianke i sie zdrzemnac" << endl;
}
void Bear::complainAboutPorridge(string heatLevel)
{
    cout << "owsianka byla " << heatLevel << endl;
}