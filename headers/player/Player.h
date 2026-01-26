#include <vector>
#include <iostream> 

#ifndef PLAYER_H
#define PLAYER_H
#include <list>
class NPC; 
class Items;
class Weapon; 

class Player {
protected:
    std::string name;
    int level;
    double experience;
    std::vector<std::string> questList;
    std::string placeOfBeing;
    NPC* npc;
    std::list <Items*> items; 
    Weapon* weapon; 

public:
    virtual void goToNewPlace(const std::string& newPlace);
    virtual void interactWithNPC(NPC* npc);
    virtual void gainExperience(double amount);
    virtual ~Player() = default;
};

#include "Items.h"
#include "Weapon.h"
#include "NPC.h"
#endif // PLAYER_H