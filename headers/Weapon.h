#pragma once
// done purly for trying something else I am aware that this is not standard.
#include <string>

class Items
{
public:
    void equipItem(void);
};

class Weapon
{
protected:
    std::string name;
    double damageMultiplier;

public:
    virtual void giveAttackBonus();
    virtual ~Weapon() = default;
};
class RangedWeapon : public Weapon, public Items
{
public:
    void equipItem();
    // overide for compiler check if this function is virutral
    void giveAttackBonus() override;
    ~RangedWeapon();
};
class MeeleWeapon : public Weapon, public Items
{
public:
    void equipItem();
    void giveAttackBonus() override;
    void giveDefenseBonus();
    ~MeeleWeapon();
};
class MagicWeapon : public Weapon, public Items
{
private:
    double additonalDemage;
    void giveAdditionalAttack();

public:
    void equipItem();

    void giveAttackBonus() override;
    ~MagicWeapon();
};
