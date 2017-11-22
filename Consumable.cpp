#include <iostream>
#include "Consumable.h"
#include "Character.h"
using namespace std;

Consumable::Consumable() {}

int Consumable::GetQuantity() const {
    return this->quantity;
}
void Consumable::SetQuantity(int quantity) {
    this->quantity = quantity;
}
void Consumable::Consume(Character *target) {
    cout << target->GetName() << " used " << this->name;
    cout << " (Level " << this->itemLevel << ")" << endl;
}