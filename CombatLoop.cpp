/*========================================================================
Combat Loop

This combat loop runs while both player and enemy are alive.
Each iteration of the loop allows for one turn by the player and one
randomized action by the enemy.
==========================================================================*/

#ifndef GROUPPROJECT_COMBAT_H
#define GROUPPROJECT_COMBAT_H

#include <iostream>
#include <ctime>
#include "Character.h"
#include "Potion.h"

using namespace std;

void Combat(Character &player1, MagicMissile missile, HealthPotion pot1, Sword sword1) {		//Player is now passed by reference to effects of batte permanent

	/*=============================================
	Variables
	===============================================*/

	int turn = 0;		// Used for the turn counter
	int enemyChoice = 0;	// Random enemy choice
	int playerChoice = 0;	// Should be 1 - 4 for action menu
    Character enemy1("Bandit", 50);

    srand(time(0));		// Used to seed rand

    cout << player1.GetName() << " enters the battle!" << endl;
	cout << enemy1.GetName() << " enters the battle!" << endl;
	/*=========================================================
	Start of The Combat Loop
	============================================================*/
    do {

        // Regenerate player's life and energy slightly
        player1.IncreaseEnergy(10);
        player1.IncreaseHealth(10);

        turn++;					//Turn counter and display
        cout << "TURN " << turn << endl;

        player1.Print();    // Display player1 attributes
        enemy1.Print();     // Display enemy1 attributes

        cout << endl;
        /*============================================================
        Player Action Menu
        ==============================================================*/
        cout << "Choose an action." << endl;

        cout << "(1) Attack		(2) Cast Spell" << endl;
        cout << "(3) Equip Weapon	(4) Use Potion" << endl;

        cin >> playerChoice;	// Player inputs Action here

        while (playerChoice < 1 || playerChoice > 4) {	//Used for Player input Validations
            cout << "Choose a number between 1 and 4" << endl;

            cin.ignore();
            cin >> playerChoice;
        };

        cout << endl;

        switch (playerChoice)	//Switch for Player Menu
        {
        case 1:				//Attack
            player1.Attack(&enemy1);
            cout << endl;
            break;
        case 2:				//Cast Spell
            player1.CastSpell(&missile, &enemy1);	//Use constructor from main for now
            cout << endl;
            break;
        case 3:
            player1.EquipWeapon(&sword1);			//Use constructor from main for now
            cout << endl;
            break;
        case 4:
            player1.UseConsumable(&pot1);			//Use constructor from main for now
            cout << endl;
            break;
        default:
            player1.Attack(&enemy1);
            cout << endl;
            break;
        }

        /*=======================================================
        Enemy Action
        =========================================================*/

        enemyChoice = rand() % 4 + 1;

        switch (enemyChoice)	//Switch for Player Menu
        {
        case 1:				//Attack
            enemy1.Attack(&player1);
            cout << endl;
            break;
        case 2:				//Cast Spell
            enemy1.CastSpell(&missile, &player1);	//Use constructor from main for now
            cout << endl;
            break;
        case 3:
            enemy1.EquipWeapon(&sword1);			//Use constructor from main for now
            cout << endl;
            break;
        case 4:
            enemy1.UseConsumable(&pot1);			//Use constructor from main for now
            cout << endl;
            break;
        default:
            enemy1.Attack(&player1);
            cout << endl;
            break;
        }
		}

    while (player1.IsAlive() && enemy1.IsAlive());

	if (player1.GetHealth() <= 0) {
		cout << "You Died" << endl;
	}
	else {
		cout << "Victory" << endl;
	}

	return;
}

#endif // !GROUPPROJECT_COMBAT_H
