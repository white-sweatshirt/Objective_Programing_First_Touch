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
    Protagonist *protagonstTeam[] = {pussInBooots, kittyCat, peunito};

    peunito->doTherapy(pussInBooots);
    kittyCat->makePlansForCapturingFlag(protagonstTeam, sizeof(protagonstTeam) / sizeof(protagonstTeam[0]));
    
    return 0;
}