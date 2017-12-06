#include <iostream>
#include "Character.h"
#include "Potion.h"
#include "CombatLoop.cpp"
using namespace std;

int main(){
	char input = 'x';

    Character player1("Mad Max", 100);      // Create a character
    Character enemy1("The Toecutter", 100); // Create a character
    Sword sword1("Master Sword", 3);        // Create a Sword (weapon)
    HealthPotion pot1(2);                   // Create a HealthPotion
    StrengthPotion pot2(3);                 // Create a StrengthPotion
    HealingSpell hSpell(1);                 // A healing spell
    MagicMissile missile(3);                // Magic Missile spell

    player1.IncreaseGold(100);              // Start the player with 100 gold

	while (input != 'q'){//ends the main game loop when the input is Q
		input = 'c'; //ensures the main part of the town loop always starts correctly
		while (input != 'a' && input != 'b' && input != 'q'){ //loops if an invalid input is selected
			cout << "You find yourself in the safe, quaint town" << endl;
			cout << "a: Rest in the tavern to heal. costs 10 gold. Current health is " << player1.GetHealth() << endl;
			cout << "b: Go exploring in the fields" << endl;
			cout << "q: Quit game" << endl;
			cin >> input;

			if (input != 'a' && input != 'b' && input != 'q'){ //warns player that an invalid input has been selected
				cout << "Please enter a listed option :";
				cin >> input;
			}
		}
		switch (input){
			case 'a' : //if player chooses 'a', heals the player and subtracts 10 gold
				if (player1.GetGoldAmount() >= 10) {
					player1.DecreaseGold(10);
					player1.IncreaseHealth(100);
                    player1.SetEnergy(100);
				}
				else {
					cout << player1.GetName() << " does not have enough gold." << endl;
				}
				break;

			case 'b' : //if player chooses 'b', starts the field loop
				input = 'a'; //makes sure the field loop doesn't end right away
				while (input != 'b' && input != 'q'){ //stays in the field until "return to town" or "quit game" is selected
					
					cout << "The fields stretch on endlessly, with the safety of the town barely visible in the distance behind you" << endl;
					cout << "You currently have " << player1.GetHealth() << " health" << endl;
					cout << "a: Wander in the fields" << endl;
					cout << "b: Return to the safety of town" << endl;
					cout << "q: Quit game" << endl;
					cin >> input;

					if (input == 'a'){
						Combat(player1, missile, pot1, sword1);
					}
					else if (input == 'b' || input == 'q') {
						//if b, game will return to town naturally, if q, game will end
					}
					else{
						cout << "Please enter a listed option " << endl << endl;	
					}
				}
                // Exit if the player dies
                if (!player1.IsAlive()) {
                    cout << "You died." << endl;
                    return 0;
                }
				break;
		}
	}
	cout << "Game Over";
	return 0;

}

