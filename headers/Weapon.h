#pragma once
// done purly for trying something else 
//I am aware that this is not standard.
#include <string>

class Items
{
public:
    virtual void equipItem(void);
    virtual int calculateBonus(int stat); // Pure virtual function for stat-based bonus
};

class Weapon: public Items
{
protected:
    std::string name;
    int damageBonus;

public:
    
    virtual ~Weapon() = default;
};

class RangedWeapon : public Weapon
{
private:
    int agilityBonus;

public:
    void equipItem();
    int calculateBonus(int agility) override; 
    ~RangedWeapon();
};

class MeeleWeapon : public Weapon
{
private:
    int strenghtBonus;

public:
    void equipItem();
    int calculateBonus(int strength) override; 
    ~MeeleWeapon();
};

class MagicWeapon : public Weapon
{
private:
    int magicalMultiplier;
    double additionalDamage;

public:
    void equipItem();
    int calculateBonus(int intelligence) override;
    ~MagicWeapon();
};
