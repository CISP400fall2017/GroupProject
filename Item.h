#ifndef GROUPPROJECT_ITEM_H
#define GROUPPROJECT_ITEM_H

#include <string>
using namespace std;

class Item {
protected:
    string name;         // The item's name
    int itemLevel;      // Item's potency is increased by this amount
public:
    // Constructors
    Item();
    Item(string name, int itemLevel);
    // Access methods
    string GetName() const;
    int GetItemLevel() const;
    virtual void Print() const;
    // Mutator methods
    void SetName(string name);
    void SetItemLevel(int itemLevel);
};

#endif //GROUPPROJECT_ITEM_H
