#include "PlayerClasses.h"

PlayerArcher::PlayerArcher(std::string name):
Player(name),Archer()
{}

PlayerWarrior::PlayerWarrior(std::string name):
Player(name),Warrior()
{}

PlayerWizzard::PlayerWizzard(std::string name):
Player(name),Wizzard()
{}