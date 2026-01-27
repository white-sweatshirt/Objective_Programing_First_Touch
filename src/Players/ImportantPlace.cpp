#include "ImportantPlace.h"
#include <iostream>

void PlaceOFImportance::giveOption(void)
{
    // TODO : implement
}

void PlaceOFImportance::show() const
{
    std::cout << "Interesting Place: " << whatIsInteresting << std::endl;
    if (interestingNPC)
    {
        std::cout << "NPC present at this location." << std::endl;
    }
    if (interestingOppone)
    {
        std::cout << "Opponent present at this location." << std::endl;
    }
}