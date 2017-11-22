#ifndef GROUPPROJECT_POTION_H
#define GROUPPROJECT_POTION_H

#include "Consumable.h"
class Character;

class Potion : public Consumable {
public:
    Potion();
    Potion(int potionLevel);
    virtual void Consume(Character *target);
};

class HealthPotion : public Potion {
public:
    HealthPotion();
    HealthPotion(int itemLevel);
    virtual void Consume(Character *target);
};
class StrengthPotion : public Potion {
public:
    StrengthPotion();
    StrengthPotion(int itemLevel);
    virtual void Consume(Character *target);
};
class EnergyPotion : public Potion {
public:
    EnergyPotion();
    EnergyPotion(int itemLevel);
    virtual void Consume(Character *target);
};
#endif //GROUPPROJECT_POTION_H
