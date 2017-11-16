//
// Created by zac on 10/20/17.
//
#include "Item.h"
#include <iostream>
using namespace std;

Item::Item() {
    this->name = "NONE";
    this->itemLevel = 1;
}
Item::Item(string name, int itemLevel) {
    this->name = name;
    this->itemLevel = itemLevel;
}
std::string Item::GetName() const {
    return name;
}
int Item::GetItemLevel() const {
    return itemLevel;
}
void Item::Print() const {
    cout << "====== " << this->name << " ======" << endl;
    cout << "Item Level: " << this->itemLevel << endl;
}
void Item::SetName(string name) {
    this->name = name;
}
void Item::SetItemLevel(int itemLevel) {
    this->itemLevel = itemLevel;
}