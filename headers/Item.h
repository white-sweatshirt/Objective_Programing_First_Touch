#pragma once
// done purly for trying something else
// I am aware that this is not standard.
#include <string>

class Item
{
    double value;
public:
    virtual void equipItem(void);
    double giveValue(void);
    virtual int calculateBonus(int stat); // Pure virtual function for stat-based bonus
    virtual void show();
};

class Weapon : public Item
{
protected:
    std::string name;
    int damageBonus;

public:
    Weapon(std::string name, int damgeBonus);
    void show() override;
    ~Weapon();
};

class RangedWeapon : public Weapon
{
private:
    int agilityBonus;

public:
    void equipItem();
    int calculateBonus(int agility) override;
    RangedWeapon(std::string name,int damegeBonus);
    ~RangedWeapon();
};

class MeeleWeapon : public Weapon
{
private:
    int strenghtBonus;

public:
    void equipItem();
    int calculateBonus(int strength) override;
    MeeleWeapon(std::string name,int damegeBonus);
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
    MagicWeapon(std::string name,int damegeBonus);
};
