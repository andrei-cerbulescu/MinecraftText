#include <iostream>
#include "./Player.h"


void decissionFunction(Player *player1) {

	std::cout << "1.Mine \n2.Fight Mobs \n3.Craft \n";
	int decission;

	std::cin >> decission;

	if (player1->inventorySpace->isFull() == true) {
		std::cout << "Invetory is full!\n";
		decissionFunction(player1);
	}

	if (player1->isDead() == true) {
		std::cout << "You died!\n";
	}

}