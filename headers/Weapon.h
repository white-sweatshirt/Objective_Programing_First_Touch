#pragma once
// done purly for trying something else I am aware that this is not standard.
#include <string>

class Weapon {
protected:
    std::string name;
    double damageMultiplier;

public:
    virtual void useInAttack() = 0;
    virtual ~Weapon() = default;
};
class RangedWeapon : public Weapon {
public:
    void equipItem();
    void giveAttackBonus();
    ~RangedWeapon() override = default;
};
class MeeleWeapon : public Weapon {
public:
    void equipItem();
    void giveAttackBonus();
    void giveDefenseBonus();
    ~MeeleWeapon() override = default;
};
class MagicWeapon : public Weapon {
public:
    void equipItem();
    void giveAdditionalAttack();
    void giveAttackBonus();
    ~MagicWeapon() override = default;
};

