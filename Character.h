/*******************************************************************************
 *                      Character class declaration
 *******************************************************************************/
#ifndef GROUPPROJECT_CHARACTER_H
#define GROUPPROJECT_CHARACTER_H

#include <string>
#include "Weapons.h"
#include "Consumable.h"
#include "Spells.h"
using namespace std;

class Spell;

class Character { // Base class for all characters
private:
    bool isAlive;
    string name;
    int health;    // Number of hit points
    int maxHealth; // Potions will not heal you beyond maxHealth
    int energy;    // Used to cast spells
    int maxEnergy; // Maximum energy
    int strength;  // Damage dealt is increased by this amount
    int defense;   // Damage received is increased by this amount
    Weapon equippedWeapon;  // Currently equipped weapon
public:
    // Constructors
    Character();
    Character(string name, int maxHealth);
    // Getters
    string GetName() const;
    int GetHealth() const;
    int GetEnergy() const;
    int GetStrength() const;
    int GetDefense() const;
    Weapon GetEquippedWeapon() const;
    void Print() const;
    bool IsAlive() const;
    // Setters
    void SetName(string name);
    void SetHealth(int healthValue);
    void IncreaseHealth(int lifeGained);
    void DecreaseHealth(int damageTaken);
    void SetEnergy(int energyValue);
    void SetStrength(int strengthValue);
    void SetDefense(int defenseValue);
    // Interaction methods
    void UseConsumable(Consumable *itemToUse);
    void EquipWeapon(Weapon *weaponToEquip);
    void Attack(Character *target);
    void CastSpell(Spell *spell, Character *target);
};

#endif //GROUPPROJECT_CHARACTER_H
