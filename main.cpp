#include "scene.h"
#include "actors.h"

int main(void)
{
    Scene *scene = new Scene();
    scene->createHome();
    scene->introducecesBearsToHome();

    vector<Bear *> bearFamily;
    bearFamily.push_back(new Bear("Brat", scene->giveLocation()));
    bearFamily.push_back(new Bear("Ojciec", scene->giveLocation()));
    bearFamily.push_back(new Bear("Matka", scene->giveLocation()));

    humanVillan *goldie = new humanVillan("Zlotowlosa", scene->giveLocation(), new Map());

    Protagonist *pussInBooots = new Protagonist("Puss in Boots", "przed domkiem", NULL);
    Protagonist *kittyCat = new Protagonist("Kitti", "przed domkiem", NULL);
    Protagonist *peunito = new Protagonist("Peunito", "przed domkiem", NULL);
    Protagonist *protagonistTeam[] = {pussInBooots, kittyCat, peunito};

    for (auto bear : bearFamily)
        bear->goesToSleep();

    peunito->doTherapy(pussInBooots);
    kittyCat->makePlansForCapturingFlag(protagonistTeam, sizeof(protagonistTeam) / sizeof(protagonistTeam[0]));
    pussInBooots->tryToStealMapFrom(goldie);
    for (auto bear : bearFamily)
        bear->wakeUp();

    goldie->askForHelpWithThief(bearFamily, pussInBooots);
    goldie->attackActor(pussInBooots);
    for (auto bear : bearFamily)
        bear->tryToCatch(pussInBooots);

    pussInBooots->transferMapOwnerShip(kittyCat);
    scene->getChanged("Latajacy domek");

    Map *map = kittyCat->throwMap();
    cout << "zmiana sceneri teraz: " << scene->giveLocation() << endl;
    pussInBooots->throwPodrigeOnVillan(bearFamily[0], "za zinmna");
    pussInBooots->throwPodrigeOnVillan(bearFamily[1], "za goraca");
    kittyCat->throwPodrigeOnVillan(bearFamily[2], "W sam raz");
    kittyCat->danceWithOther(pussInBooots);

    pussInBooots->getMap(map);
    pussInBooots->readMagicalChangingSceneMap(scene);

    return 0;
}