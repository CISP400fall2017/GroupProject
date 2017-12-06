/*******************************************************************************
 *                      Character class definition
 *******************************************************************************/

#include <iostream>
#include <iomanip>
#include "Character.h"
using namespace std;

/********************************************************************************
*   Characters: Constructors                                                    *
*********************************************************************************/
Character::Character() {
    this->isAlive = true;
    this->name = "Unknown Entity";
    this->maxHealth = 100;
    this->health = this->maxHealth;
    this->maxEnergy = 100;
    this->energy = this->maxEnergy;
    this->strength = 10;
    this->defense = 0;
    this->goldCoins = 0;
}
Character::Character(string name, int maxHealth) {
    this->isAlive = true;
    this->name = name;
    this->maxHealth = maxHealth;
    this->health = this->maxHealth;
    this->maxEnergy = 100;
    this->energy = this->maxEnergy;
    this->strength = 10;
    this->defense = 0;
    this->goldCoins = 0;
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
int Character::GetGoldAmount() const {
    return this->goldCoins;
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
    // Increase the character's health.
    cout << this->name << " gains ";
    // Health cannot exceed maxHealth
    if ((this->health + lifeGained) < this->maxHealth) {
        this->health += lifeGained;
        cout << lifeGained;
    } else {
        cout << this->maxHealth - this->health;
        this->health = this->maxHealth;
    }
    cout << " health!" << endl;
}
void Character::DecreaseHealth(int damageTaken) {

    cout << this->name << " takes " << damageTaken << " damage!" << endl;

    if ((this->health - damageTaken) > 0) {
        this->health -= damageTaken;
    } else {
        this->health = 0;
        this->isAlive = false;
        cout << this->name << " has died." << endl;
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
void Character::IncreaseGold(int increaseBy) {
    if (increaseBy > 0) { // Only accept positive amounts
        cout << this->name << " gains " << increaseBy << " gold." << endl;
        this->goldCoins += increaseBy;
    }
}
void Character::DecreaseGold(int decreaseBy) {
    if (this->goldCoins - decreaseBy >= 0) {
        this->goldCoins -= decreaseBy;
    }
    else { // Character does not have enough gold
        cout << this->name << " does not have enough gold." << endl;
        return;
    }
}
bool Character::IsAlive() const {
    // Return true if the Character is alive
    return this->isAlive;
}
/********************************************************************************
*   Characters: Interaction Methods                                             *
*********************************************************************************/
void Character::UseConsumable(Consumable *itemToUse) {
    itemToUse->Consume(this);
}
void Character::EquipWeapon(Weapon *weaponToEquip) {
	this->equippedWeapon = *weaponToEquip;
		cout << this->name << " equipped " << equippedWeapon.GetName();
}
void Character::Attack(Character *target) {
    // Deal damage that is mitigated by the target's defense stat
    int damageDealt = (this->strength + this->equippedWeapon.GetWeaponDamage()) - target->defense;

   cout << this->name << " attacks " << target->GetName() << "!" << endl;

    if (damageDealt > 0) {  // Target takes damage
        target->DecreaseHealth(damageDealt);
    }
    else { // Target defense is too high, no damage taken
        cout << "!" << endl << "The attack has no effect!" << endl;
    }
}
void Character::CastSpell(Spell *spell, Character *target) {
    // Cast a spell at a target
    if (this->energy - spell->GetTotalEnergyCost() >= 0) {
        // Player has enough energy to cast the spell
        cout << this->name << " casts " << spell->GetSpellName();
        cout << " (Level " << spell->GetSpellLevel() << ") at ";
        cout << target->GetName() << "!" << endl;
        spell->Cast(target);
        this->energy -= spell->GetTotalEnergyCost();
    }
    else {
        // Player does not have enough energy to cast the spell
        cout << this->name << " does not have enough energy to cast ";
        cout << spell->GetSpellName() << "." << endl;
    }
}
