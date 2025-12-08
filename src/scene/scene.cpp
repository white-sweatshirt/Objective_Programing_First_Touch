#include "scene.h"
void Scene::createHome()
{
    this->currentState="Scene with Home of Three Bears";
}
void Scene::introducecesBearsToHome()
{
    cout<<"Drogie Misie jestesmy u was w domu" <<endl <<this->currentState<<endl;
}
void Scene::createCrystalCave()
{
    this->currentState="crystal Cave";
}