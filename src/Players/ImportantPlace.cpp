#include "ImportantPlace.h"
#include <iostream>
#include "ActiveActor.h"

void PlaceOFImportance::show() const
{
    std::cout << "Interesting Place: " << description << std::endl;
    if (interestingNPC)
    {
        std::cout << "NPC present at this location." << std::endl;
        this->interestingNPC->show();
    }
    if (enemy)
    {
        std::cout << "Opponent present at this location.\n Importnat info:" << std::endl;
        this->enemy->giveVitalInfo();
    }
}