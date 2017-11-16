#include <iostream>
#include <iomanip>
#include "Character.h"
using namespace std;

/********************************************************************************
*   Characters: Constructors                                                    *
*********************************************************************************/
Character::Character() {
    this->name = "";
    this->maxHealth = 100;
    this->health = this->maxHealth;
    this->maxEnergy = 100;
    this->energy = this->maxEnergy;
    this->strength = 10;
    this->defense = 0;
}
Character::Character(string name, int maxHealth) {
    this->name = name;
    this->maxHealth = maxHealth;
    this->health = this->maxHealth;
    this->maxEnergy = 100;
    this->energy = this->maxEnergy;
    this->strength = 10;
    this->defense = 0;
}
/********************************************************************************
*   Characters: Accessors                                                      *
*********************************************************************************/
string Character::GetName() const {
    return this->name;
}
int Character::GetHealth() const {
    return this->health;
}
int Character::GetEnergy() const {
    return this->energy;
}
int Character::GetStrength() const {
    return this->strength;
}
int Character::GetDefense() const {
    return this->defense;
}
Weapon Character::GetEquippedWeapon() const {
    return this->equippedWeapon;
}
void Character::Print() const {
    cout << "====== " << this->name << " STATS ======" << endl;
    cout << "Health....:    " << setw(4) << right << this->health << endl;
    cout << "Energy....:    " << setw(4) << right << this->energy << endl;
    cout << "Strength..:    " << setw(4) << right << this->strength << endl;
    cout << "Defense...:    " << setw(4) << right << this->defense << endl;
    cout << endl;
}
/********************************************************************************
*   Characters: Mutator Methods                                                 *
*********************************************************************************/
void Character::SetName(string name) {
    this->name = name;
}
void Character::SetHealth(int healthValue) {
    this->health = healthValue;
}
void Character::IncreaseHealth(int lifeGained) {

    cout << this->name << " is healed for ";
    if ((this->health + lifeGained) < this->maxHealth) {
        this->health += lifeGained;
        cout << lifeGained;
    } else {
        cout << this->maxHealth - this->health;
        this->health = this->maxHealth;
    }
    cout << "!" << endl;
}
void Character::DecreaseHealth(int damageTaken) {
    // Damage taken is reduced by defense stat
    int healthLost = damageTaken - this->defense;
    // Reduce health
    if ((this->health - healthLost) > 0) {
        this->health -= healthLost;
    } else {
        this->health = 0;
    }
}
void Character::SetEnergy(int energyValue) {
    this->energy = energyValue;
}
void Character::SetStrength(int strengthValue) {
    this->strength = strengthValue;
}
void Character::SetDefense(int defenseValue) {
    this->defense = defenseValue;
}
/********************************************************************************
*   Characters: Interaction Methods                                             *
*********************************************************************************/
void Character::UseConsumable(Consumable *itemToUse) {
    itemToUse->Consume(this);
}
void Character::EquipWeapon(Weapon *weaponToEquip) {
    this->equippedWeapon = *weaponToEquip;
}
void Character::Attack(Character *target) {
    int damageDealt = (this->strength + this->equippedWeapon.GetWeaponDamage()) - target->defense;

    cout << this->name << " attacks " << target->GetName();

    if (damageDealt > 0) {  // Target takes damage
        cout << " for " << damageDealt << " damage!" << endl;
        if (target->GetHealth() > 0) {
            target->DecreaseHealth(damageDealt);
        } else { // Target is already dead
            cout << "Overkill!" << endl;
        }
    }
    else { // Target defense is too high, no damage taken
        cout << "!" << endl << "The attack has no effect!" << endl;
    }
}


