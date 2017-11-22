#include <iostream>
#include "Potion.h"
#include "Character.h"
using namespace std;

/*******************************************************************************
*   Potion base class
*******************************************************************************/
Potion::Potion() {
    this->SetName("Mystery Potion");
    this->SetItemLevel(0);
}
Potion::Potion(int potionLevel) {
    this->SetItemLevel(potionLevel);
}
void Potion::Consume(Character *target) {
    cout << "Using a potion!" << endl;
}
/*******************************************************************************
*   Health Potions
*******************************************************************************/
HealthPotion::HealthPotion() {
    this->name = "Health Potion";
    this->itemLevel = 1;
}
HealthPotion::HealthPotion(int itemLevel) {
    this->name = "Health Potion";
    this->itemLevel = itemLevel;
}
void HealthPotion::Consume(Character *target) {
    int amountHealed = this->itemLevel * 10;
    Consumable::Consume(target);
    target->IncreaseHealth(amountHealed);
}
/*******************************************************************************
*   Strength Potions
*******************************************************************************/
StrengthPotion::StrengthPotion() {
    this->name = "Strength Potion";
    this->itemLevel = 1;
}
StrengthPotion::StrengthPotion(int itemLevel) {
    this->name = "Strength Potion";
    this->itemLevel = itemLevel;
}
void StrengthPotion::Consume(Character *target) {
    int strengthGained = this->itemLevel * 3;
    Consumable::Consume(target);
    cout << target->GetName() << " gains ";
    cout << strengthGained << " strength!" << endl;
    target->SetStrength(target->GetStrength() + strengthGained);
}
/*******************************************************************************
*   Energy Potions
*******************************************************************************/
EnergyPotion::EnergyPotion() {
    this->name = "Energy Potion";
    this->itemLevel = 1;
}
EnergyPotion::EnergyPotion(int itemLevel) {
    this->name = "Energy Potion";
    this->itemLevel = itemLevel;
}
void EnergyPotion::Consume(Character *target) {
    int energyGained = this->itemLevel * 3;
    Consumable::Consume(target);
    cout << target->GetName() << " gains ";
    cout << energyGained << " energy!" << endl;
    target->SetStrength(target->GetEnergy() + energyGained);
}