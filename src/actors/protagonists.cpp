#include "protagonists.h"
/******************************/
Protagonist::Protagonist(string name, string startingLocation, Map *map) : Actor(name, startingLocation, map)
{
}
void Protagonist::doTherapy(Protagonist *target)
{
    cout << this->giveName() << "staram sie pomoc: " << target->giveName() << endl;
}
void Protagonist::talkWithGhost(GhostOfPast *ghost)
{
    cout << "hej jestem kot w butach jakim duchem jestes? " << endl;
    ghost->tellAboutItsellfToHero(this);
    cout << "chyba powiniem wyciagnoc jakies wnioski co do siebie ...." << endl;
}
void Protagonist::throwPodrigeOnVillan(Bear *villanBear, string heatLevel)
{
    cout << "rzucam owsianka w " << villanBear->giveName() << endl;
    
}
Protagonist::~Protagonist()
{}
void Protagonist::tryToStealMapFrom(Actor *target)
{
    if (!checkWheterIsFriend(target))
    {
        cout << "mistrzowsko podbieram mape " << target->giveName() << endl;
        this->map = target->loseMap();
    }
    else
        cout << "probowalem zabrac mape sojusznikowi /n";
}
void GhostOfPast::tellAboutItsellfToHero(Protagonist *hero)
{
    cout << "jestem duchem twojej przeszlosci bylem: " << this->whatItDid << endl;
}