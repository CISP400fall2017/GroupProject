#ifndef GROUPPROJECT_WEAPON_H
#define GROUPPROJECT_WEAPON_H

#include "Item.h"

class Weapon : public Item {
protected:
    int weaponDamage;   // Player's damage is increased by this amount
    // TODO implement weapon durability
    // TODO implement weapon damage based on item level
public:
    // Constructors
    Weapon();
    Weapon(string weaponName, int weaponDamage);
    // Getters
    int GetWeaponDamage() const;
    void Print() const;
    // Setters
    void SetWeaponDamage(int weaponDamage);
};

class Dagger : public Weapon {
public:
    Dagger();
    Dagger(string daggerName, int daggerDamage);
};

class Sword : public Weapon {
public:
    Sword();
    Sword(string swordName, int daggerDamage);

};
#endif //GROUPPROJECT_WEAPON_H
