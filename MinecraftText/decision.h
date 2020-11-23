#include <iostream>
#include "./Player.h"
#include "./mine.h"
#include "Fight/Fight.h"
#include <stdlib.h>

void decisionFunction(Player *player1) {

	bool stillPlaying = true;
	Fight* curentFight;

	while (stillPlaying == true) {

		std::cout << "1.Mine \n2.Fight Mobs \n3.Craft \n4.See Inventory\n9.Exit\n";

		int decision;
		std::cin >> decision;

		switch (decision) {

			case 1:
				mineFunction(player1);
				break;

			case 2:
				curentFight = new Fight(player1);
				curentFight->fightFunction();
				delete curentFight;
				break;

			case 4:
				player1->inventorySpace->displayInventory();
				break;

			case 9:
				player1->endGame();
				stillPlaying = false;
				break;

			default:
				std::cout << "Unknown command!\n";
		}

		if (stillPlaying == true) {
			if (player1->inventorySpace->isFull() == true) {
				std::cout << "Invetory is full!\n";
			}

			if (player1->isDead() == true) {
				std::cout << "You died!\n";
			}

			std::cout << "\n";
		}
	}

}
