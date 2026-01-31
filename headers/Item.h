#ifndef ITEM_H
#define ITEM_H
// done purly for trying something else
// I am aware that this is not technicly standard.
#include <string>
class ActiveActor;
class Item
{
    double value;

public:
    double giveValue(void);
    virtual int calculateBonus(ActiveActor *const actor); // Pure virtual function for stat-based bonus
    virtual void show();
    virtual ~Item() = default;
    Item(double value);
    
};

class Weapon : public Item
{
protected:
    std::string name;
    int damageBonus;

public:
    Weapon(std::string name, int damgeBonus);
    void show() override;
    // =0 zero dontets that this purly virutral function implemntetion
    virtual int calculateBonus(ActiveActor *const actor) = 0;
    void setName(std::string desc);
    virtual ~Weapon() override = default; // setting deconstror to deflaut
};

class RangedWeapon : public Weapon
{
private:
    int agilityBonus;

public:
    // const deklaruje ze nic nie zmienie w aktorze.
    int calculateBonus(ActiveActor *const actor) override;
    RangedWeapon(std::string name, int damegeBonus);
    ~RangedWeapon() = default;
};

class MeeleWeapon : public Weapon
{
private:
    int strenghtBonus;

public:
    int calculateBonus(ActiveActor *const actor) override;
    MeeleWeapon(std::string name, int damegeBonus);
    ~MeeleWeapon() = default;
};

class MagicWeapon : public Weapon
{
private:
    int magicalMultiplier;
    double additionalDamage;

public:
    int calculateBonus(ActiveActor *actor) override;
    ~MagicWeapon() = default;
    MagicWeapon(std::string name, int damegeBonus);
};
#endif