#include <iostream>
#include "./Player.h"
#include "./mine.h"


void decissionFunction(Player *player1) {

	std::cout << "1.Mine \n2.Fight Mobs \n3.Craft \n4.See Inventory\n";
	int decission;

	std::cin >> decission;

	if (decission == 1) {
		mineFunction(player1);
	}

	if (decission == 4) {
		player1->inventorySpace->displayInventory();
	}

	if (player1->inventorySpace->isFull() == true) {
		std::cout << "Invetory is full!\n";
		decissionFunction(player1);
	}

	if (player1->isDead() == true) {
		std::cout << "You died!\n";
	}

	std::cout << "-------------------\n";

	decissionFunction(player1);

}