#ifndef PLAYER_CLASSES_H
#define PLAYER_CLASSES_H
#include "Player.h"
#include "ActiveActor.h"
class PlayerArcher : public Archer, public Player
 {
public:
    void performRiposte();
    void attackWithBow();
    ~PlayerArcher() override = default;
};
class PlayerWizzard: public Wizzard , public Player
{

};
class PlayerWarrior:public Warrior, public Player
{
    
};
#endif