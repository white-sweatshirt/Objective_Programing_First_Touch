#include "protagonists.h"
/******************************/
Protagonist::Protagonist(string name, string startingLocation, Map *map) : Actor(name, startingLocation, map),
                                                                           isStressed(false)
{
}
Protagonist::Protagonist()
{
    this->isStressed = false;
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
    villanBear->complainAboutPorridge(heatLevel);
}
Protagonist::~Protagonist()
{
}
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
void Protagonist::makePlansForCapturingFlag(Protagonist *team[], int peopleInTeam)
{
    cout << this->giveName() << " proponuje przejac mape teraz\n";
    for (int i = 0; i < peopleInTeam; i++)
        if (this != *(team + i))
            cout << (*(team + i))->giveName() << " zgadza sie z propzycja !\n";
}
GhostOfPast::GhostOfPast(string whatIDid) : whatIDid(whatIDid)
{
}
void GhostOfPast::tellAboutItsellfToHero(Protagonist *hero)
{
    cout << "jestem duchem twojej przeszlosci bylem: " << this->whatIDid << endl;
}
GhostOfPast::~GhostOfPast()
{
}