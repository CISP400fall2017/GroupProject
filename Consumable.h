#ifndef GROUPPROJECT_CONSUMABLE_H
#define GROUPPROJECT_CONSUMABLE_H

#include "Item.h"

class Character;
class Consumable : public Item {
protected:
    int quantity;       // Quantity held by player
public:
    Consumable();
    int GetQuantity() const;
    void SetQuantity(int quantity);
    virtual void Consume(Character *target) = 0;
};


#endif //GROUPPROJECT_CONSUMABLE_H
