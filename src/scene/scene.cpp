#include "scene.h"
void Scene::createHome()
{
    this->currentState = "Scene with Home of Three Bears";
}
void Scene::introducecesBearsToHome()
{
    cout << "Drogie Misie jestesmy u was w domu" << endl
         << this->currentState << endl;
}
string Scene::giveLocation()
{
    return this->currentState;
}
vector<GhostOfPast *> *Scene::createCrystalCave()
{
    this->currentState = "Krysztalowa jaskinia Kot w Butach walczy z swoja przeszlosica!\n";
    vector<GhostOfPast *> *a;
    a->push_back(new GhostOfPast("Blem samolubny i zapotrzony w siebie"));
    a->push_back(new GhostOfPast("Jestem Bylem zbyt zapotrzeony w to jak mnie odbierano i nic wiecej"));
    a->push_back(new GhostOfPast("Tylko sipewalem i o nic nie dbalem"));
    a->push_back(new GhostOfPast("Zajmowalem sie jedynie dobrym jedzeniem"));
    a->push_back(new GhostOfPast("Zbytnio duzo gralem w karty"));
    a->push_back(new GhostOfPast("Przejmowalem sie jedynie silownia"));
    a->push_back(new GhostOfPast("Tylko zabawa byla mi w glowie"));
}
