#include "scene.h"
#include "actors.h"

void seperateConversations()
{
    cout << "\n****************************************\n";
}

template <class pointerToVector>
void clearVectorOfPointers(pointerToVector place)
{
    // deletion function in order to standarise deletion of vector of pointers
    for (auto w : place)
        delete w;
    place.clear();
}

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

    Protagonist *pussInBooots = new Protagonist("Kot w butach", "przed domkiem", NULL);
    Protagonist *kittyCat = new Protagonist("Kitti", "przed domkiem", NULL);
    Protagonist *perritio = new Protagonist("Perritio", "przed domkiem", NULL);
    Protagonist *protagonistTeam[] = {pussInBooots, kittyCat, perritio};

    for (auto bear : bearFamily)
        bear->goesToSleep();

    perritio->doTherapy(pussInBooots);
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
    seperateConversations();
    Map *map = kittyCat->throwMap();
    cout << "zmiana sceneri teraz: " << scene->giveLocation() << endl;
    pussInBooots->throwPodrigeOnVillan(bearFamily[0], "za zinmna");
    pussInBooots->throwPodrigeOnVillan(bearFamily[1], "za goraca");
    kittyCat->throwPodrigeOnVillan(bearFamily[2], "W sam raz");

    kittyCat->danceWithOther(pussInBooots);
    pussInBooots->getMap(map);
    pussInBooots->readMagicalChangingSceneMap(scene);

    seperateConversations();

    goldie->captureHero(&perritio);

    // perrito is captured and as such is not acessable

    goldie->goToNewPlace("Pod mostem miesce zasadzki");
    for (auto bear : bearFamily)
        bear->goToNewPlace("Pod mostem miesce zasadzki");
    seperateConversations();
    kittyCat->goToOtherActor(goldie);
    perritio = kittyCat->freeHeroFromCaptureOfVIllan(goldie);

    pussInBooots->goToNewPlace(scene->giveLocation());
    vector<GhostOfPast *> *ghosts = scene->createCrystalCave();

    Death *death = new Death();
    seperateConversations();

    for (auto ghost : *ghosts)
        pussInBooots->talkWithGhost(ghost);

    death->scareHero(pussInBooots);

    for (auto ghost : *ghosts)
        death->destroyGhost(ghost);

    clearVectorOfPointers(bearFamily);
    clearVectorOfPointers(*ghosts);

    delete pussInBooots;
    delete kittyCat;
    delete death;
    delete goldie;
    delete ghosts;
    return 0;
}