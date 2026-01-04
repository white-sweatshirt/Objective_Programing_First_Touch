#include "scene.h"
void Scene::createHome()
{
    this->currentState = "Domek 3 misiow";
}
void Scene::changeToFinalScene()
{
    cout << "zmieniamy scene na ostateczna!\n";
    this->currentState="Krater upadlej gwiazdy";
}
void Scene::introducecesBearsToHome()
{
    cout << "Drogie Misie jestesmy u was w domu" << endl
         << this->currentState << endl;
}

void Scene::getChanged(string newScene)
{
    this->currentState = newScene;
}

string Scene::giveLocation()
{
    return this->currentState;
}
vector<GhostOfPast *> *Scene::createCrystalCave()
{
    this->currentState = "Krysztalowa jaskinia Kot w Butach walczy z swoja przeszlosica!\n";
    vector<GhostOfPast *> *a = new vector<GhostOfPast *>;
    a->push_back(new GhostOfPast("Bylem samolubny i zapotrzony w siebie"));
    a->push_back(new GhostOfPast("Jestem Bylem zbyt zapotrzeony w to jak mnie odbierano i nic wiecej"));
    a->push_back(new GhostOfPast("Tylko sipewalem i o nic nie dbalem"));
    a->push_back(new GhostOfPast("Zajmowalem sie jedynie dobrym jedzeniem"));
    a->push_back(new GhostOfPast("Zbytnio duzo gralem w karty"));
    a->push_back(new GhostOfPast("Przejmowalem sie jedynie silownia"));
    a->push_back(new GhostOfPast("Tylko zabawa byla mi w glowie"));
    return a;
}
void Scene::createEndingScene()
{
    this->currentState="Polanka pod gwiazdami";
}