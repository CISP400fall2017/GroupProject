#include <iostream>
#include "Character.h"
#include "Potion.h"
using namespace std;

int main() {

    Character player1("Mad Max", 100);      // Create a character
    Character enemy1("The Toecutter", 100); // Create a character
    Sword sword1("Master Sword", 3);        // Create a Sword (weapon)
    HealthPotion pot1(2);                   // Create a HealthPotion
    StrengthPotion pot2(3);                 // Create a StrengthPotion
    HealingSpell hSpell(1);                 // A healing spell
    MagicMissile missile(3);                // Magic Missile spell


    // Demonstration of combat between 2 Characters
    cout << player1.GetName() << " enters the battle!" << endl;
    cout << enemy1.GetName() << " enters the battle!" << endl;

    player1.Print();    // Display player1 attributes
    enemy1.Print();     // Display enemy1 attributes

    // Player attacks enemy
    player1.Attack(&enemy1);
    enemy1.Attack(&player1);
    cout << endl;

    // Test use of strength potion
    player1.UseConsumable(&pot2);   // Increase player1 strength
    cout << endl;

    // Player attacks enemy
    player1.Attack(&enemy1);
    cout << endl;

    // Test use of healing spell
    player1.CastSpell(&hSpell, &enemy1);
    cout << endl;

    // Test use of magic missile spell
    player1.CastSpell(&missile, &enemy1);
    cout << endl;

    // Enemy attacks player
    enemy1.Attack(&player1);
    cout << endl;

    // Test use of health potion
    player1.UseConsumable(&pot1);   // Replenish player1 health
    cout << endl;

    player1.Print();
    enemy1.Print();

    return 0;
}