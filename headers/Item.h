#pragma once
// done purly for trying something else
// I am aware that this is not technicly standard.
#include <string>

class Item
{
    double value;
public:
    virtual void equipItem(void);
    double giveValue(void);
    virtual int calculateBonus(int stat); // Pure virtual function for stat-based bonus
    virtual void show();
    virtual ~Item() = default;
};

class Weapon : public Item
{
protected:
    std::string name;
    int damageBonus;

public:
    Weapon(std::string name, int damgeBonus);
    void show() override;
    ~Weapon()override = default;// setting deconstror to deflaut
};

class RangedWeapon : public Weapon
{
private:
    int agilityBonus;

public:
    void equipItem();
    int calculateBonus(int agility) override;
    RangedWeapon(std::string name,int damegeBonus);
    ~RangedWeapon()=default;
};

class MeeleWeapon : public Weapon
{
private:
    int strenghtBonus;

public:
    void equipItem();
    int calculateBonus(int strength) override;
    MeeleWeapon(std::string name,int damegeBonus);
    ~MeeleWeapon()= default;
};

class MagicWeapon : public Weapon
{
private:
    int magicalMultiplier;
    double additionalDamage;

public:
    int calculateBonus(int intelligence) override;
    ~MagicWeapon() = default;
    MagicWeapon(std::string name,int damegeBonus);
};
