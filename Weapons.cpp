/*******************************************************************************
 *              Class definitions for all Weapon types
*******************************************************************************/

#include <iostream>
#include "Weapons.h"
using namespace std;

/*******************************************************************************
*   Weapon base class
*******************************************************************************/
// Weapon::Constructors
Weapon::Weapon() {
    this->name = "Mystery Weapon";
    this->weaponDamage = 0;
}
Weapon::Weapon(string weaponName, int weaponDamage) {
    this->name = weaponName;
    this->weaponDamage = weaponDamage;
}
// Weapon::Accessors
int Weapon::GetWeaponDamage() const {
    return this->weaponDamage;
}
void Weapon::Print() const {
    cout << "====== " << this->name << " ======" << endl;
    cout << "Damage: " << this->weaponDamage << endl;
}
// Weapon::Mutators
void Weapon::SetWeaponDamage(int weaponDamage) {
    this->weaponDamage = weaponDamage;
}
/*******************************************************************************
*   Swords
*******************************************************************************/
Sword::Sword() {
    this->name = "Sword";
    this->weaponDamage = 15;
}
Sword::Sword(string swordName, int itemLevel) {
    this->name = swordName;
    this->itemLevel = itemLevel;
    this->weaponDamage = itemLevel * 10;
}
/*******************************************************************************
*   Daggers
*******************************************************************************/
Dagger::Dagger() {
    this->name = "Dagger";
    this->weaponDamage = 5;
}
Dagger::Dagger(string daggerName, int itemLevel) {
    this->name = daggerName;
    this->itemLevel = itemLevel;
    this->weaponDamage = itemLevel * 5;
}