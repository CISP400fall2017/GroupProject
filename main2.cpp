#include <iostream>


using namespace std;

int main(){
	char input = 'x';

	while (input != 'q'){//ends the main game loop when the input is Q
		input = 'c'; //ensures the main part of the town loop always starts correctly
		while (input != 'a' && input != 'b' && input != 'q'){ //loops if an invalid input is selected
			cout << "You find yourself in the safe, quaint town" << endl;
			cout << "a: rest in the tavern to heal. costs 10 gold. Current health is " << player1.GetHealth() << endl;
			cout << "b: go exploring in the fields" << endl;
			cout << "q: quit game" << endl;
			cin >> input;

			if (input != 'a' && input != 'b' && input != 'q'){ //warns player that an invalid input has been selected
				cout << "Please enter a listed option :";
				cin >> input;
			}
		}
		switch (input){
			case 'a' : //if player chooses 'a', heals the player and subtracts 10 gold
				player1.LoseGold(10);
				player1.IncreaseHealth(100);
				break;
			case 'b' : //if player chooses 'b', starts the field loop
				input = 'a'; //makes sure the field loop doesn't end right away
				while (input != 'b' && input != 'q'){ //stays in the field until "return to town" or "quit game" is selected
					
					cout << "The fields stretch on endlessly, with the safety of the town barely visible in the distance behind you" << endl;
					cout << "You currently have " << player1.GetHealth() << " health" << endl;
					cout << "a: Wander in the fields" << endl;
					cout << "b: Return to the safety of town" << endl;
					cout << "q: quit game" << endl;
					cin >> input;
					if (input == 'a'){
						//combat(player1, etc, etc);// FIX THIS PART HERE
					}
					else if (input == 'b' || input == 'q'){
						//if b, game will return to town naturally, if q, game will end
					}
					else{
						cout << "Please enter a listed option " << endl << endl;	
					}

				}
				break;
		}
	



	}
	cout << "Game Over";
	return 0;

}

